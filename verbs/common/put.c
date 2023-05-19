/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-13 13:53:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 11:37:14
 * @FilePath: \mysticism-mud\verbs\common\put.c
 * @Description:  put -- 出牌指令
 *                put(p) + 数字序列，表示打出该数字序列手牌
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
 

 inherit _VERB;
 inherit PATH_DIR "verbs/inherit/obj_func";
#include <ansi.h>
 
 protected void create()
{
    verb::create();
    setVerb("put");
    setSynonyms("p");
    setRules("", "STR", "OBJ");
    setErrorMessage("你想出什么牌?");
}

mixed do_put()
{
    object fo;
    write("你已跳过本回合\n");
    fo = this_player()->fight_object();
    fo -> put_card_d(0);
    return 1;
}

mixed can_put()
{
    if(! this_player()->is_fight_user())
        return "目前不在战斗当中\n";
    else
        return 1;
}



mixed can_put_str(string str)
{
    string *item,*strs;
    int n=0;
    if(! this_player()->is_fight_user())
        return "目前不在战斗当中\n";
    else
    {   
        item = explode(str," ");
        foreach( string s in item)
        {   
            if((s[0] != 0) )
            {
                //使用正则表达式判断输入是否为纯数字
                strs = pcre_match_all(s,"\\D" ); 
                if(sizeof(strs))
                {
                    return "请输入有效地出牌指令\n";
                }
                n++;
            }
        }
        if(n != 0)
            return 1;
        else return "没有有效地出牌指令\n"; 
    }
    return 1;
}

mixed do_put_str(string str)
{
    string *strs;
    int *ins,n,card_n;
    object fo;
    fo = this_player()->fight_object();
    //获取当前手牌数量
    card_n = fo->get_card_num(this_player());
    ins = ({});
    //使用正则表达式判获取数字
    strs = pcre_match_all(str,"\\d+" ); 
    foreach(string *st in strs)
    {
        n = to_int(st[0]);
        foreach(int i in ins)
        {
            if(i == n)
                {
                    write(HBRED "输入的出牌号码不可重复"+NOR+"\n");
                    return 0;
                }
        }
        if(n >= card_n)
        {
            write(HBRED "输入的出牌号码不正确\n" NOR);
            return 0;
        }
        ins += ({n});
    }
    fo -> put_card_d(ins,this_player());
    return 1;
}



int help(object me)
{
    write(@HELP
指令格式 : put（p） + 数字0 + 数字1 .......

这是put指令，可以按照输出的数字序列以此打出该序列数字代表的手牌
数字x 中的x为0-9且不相互重复的数字
使用put指令后自动结束当前战斗回合
HELP );
    return 1;
}
