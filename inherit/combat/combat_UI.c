/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-26 19:38:34
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI.c
 * @Description: 战斗UI 基类
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
#include  <combat.h>
#include <mxp.h>
inherit INHERIT_PATH "combat/combat_base";
//显示一个fighter_data 项的内容
string print_line(object *ob,object ob_user,int type)
{
    object o;
    int n,line_num,num = sizeof(ob);
    string s="";
    string *str=allocate(3,"");
    line_num = num / 3;
    if(num == 0)
        s += sprintf(" |%-61s| \n", "");
    else
    {
        for(int i=0; i<= line_num ;i ++){
            for(int j=0; j<=2; j++){
                n = i*3+j;
                if(n < num )
                {
                    o = ob[n];
                    str[j] = n+"."+o->mxp_sprintf(o->print_mxp_name_all(type),18,ob_user);
                }
                else str[j] = "--";
            }
            s += sprintf(" |%-20s%-20s%-20s | \n", str[0], str[1], str[2]);
        }
    }
    return s;
}

string print_ob1_ent(object *obs,int type){return "";}

string ob2_status(object *ob)
{
    string msg;
    msg = HIC "≡" HIY "┌─────────────────────────────────────────────────────────────┐" HIC "≡\n" NOR;
    msg += sprintf(" |%-61s| \n", "");
    return msg;
}

string ob2_equip(object *ob)
{
    string msg;
    msg = HIC "≡"HIY"╞═════════════════════════════════════════════════════════════╡" HIC "≡\n" NOR;
    msg += sprintf(" |%-61s| \n", "");
    return msg;
}

string ob2_cards(object *ob)
{
    string msg;
    msg =HIC "≡" "╞═════════════════════════════════════════════════════════════╡" HIC "≡\n" NOR;
    msg += sprintf(" |%-61s| \n", "对方手牌状态：未知");
    return msg;
}

string out_area(object *ob_1,object *ob_2)
{
    string msg;
    msg = HIR "≡" HIR"╞═════════════════════════════════════════════════════════════╡" HIR "≡\n" NOR;
    //msg += print_line(ob2_data->get_summon());
    msg += GRN " ╞═════════════════════════════════════════════════════════════╡"  "\n" NOR;
    //msg += print_line(env_obj);
    msg += GRN" ╞═════════════════════════════════════════════════════════════╡"  "\n" NOR;
    msg += msg += print_ob1_ent(ob_1,SUMMON);
    msg += HIR "≡" HIR "╞═════════════════════════════════════════════════════════════╡" HIR "≡\n" NOR;
    return msg;
}

string ob1_cards(object *ob)
{
    string msg="";
    msg = msg += print_ob1_ent(ob,CARD);
    msg +=HIC "≡" "╞═════════════════════════════════════════════════════════════╡" HIC "≡\n" NOR;
    return msg;
}
string ob1_equip(object *ob)
{
    string msg="";
    msg += msg += print_ob1_ent(ob,EQUIP);
    msg += HIC "≡" HIY"╞═════════════════════════════════════════════════════════════╡" HIC "≡\n" NOR;
    return msg;
}

string ob1_status(object *ob)
{
    string msg="";
    msg += print_ob1_ent(ob,STATUS);
    msg += HIC "≡" HIY "└─────────────────────────────────────────────────────────────┘" HIC "≡\n" NOR;
    msg += "请选择出牌顺序（p + 数字0 + 数字1 + .....）注意请用空格分隔数字 \n";
    msg += "<数字x> 为0-9数字，p 后面的每一个数字代表相应的手牌，最多10张 ";
    return msg;
}
