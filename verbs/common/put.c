/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-13 13:53:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-14 17:49:15
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
    //object me = this_player();
    write("你想出什么牌？\n");
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
    if(! this_player()->is_fight_user())
        return "目前不在战斗当中\n";
    else
        return 1;
}

mixed do_put_str(string str)
{
    write(str + "\n");
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