/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-24 15:14:43
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI.c
 * @Description: 战斗UI 基类
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
#include  <combat.h>
inherit INHERIT_PATH "combat/combat_base";
//显示一个fighter_data 项的内容
string print_line(object *ob)
{
    int line_num,num = sizeof(ob);
    string s="";
    string *str=allocate(6,"");
    line_num = num / 6;
    if(num == 0)
        s += sprintf(" |%-51s| \n", "");
    else
    {
        for(int i=0; i<= line_num ;i ++){
            for(int j=0; j<=5; j++){
                if(i*6+j < num )
                {
                    str[j] = (ob[i*6+j]->print_name());
                }
                else str[j] = "--";
            }
            s += sprintf(" |%-9s%-8s%-8s%-8s%-9s%-9s| \n", str[0], str[1], str[2], str[3], str[4], str[5]);
        }
    }
    return s;
}

string print_ob1_ent(object *obs){return "";}

string ob2_status(object *ob)
{
    string msg;
    msg = HIC "≡" HIY "┌───────────────────────────────────────────────────┐" HIC "≡\n" NOR;
    msg += sprintf(" |%-51s| \n", "");
    return msg;
}

string ob2_equip(object *ob)
{
    string msg;
    msg = " ╞═══════════════════════════════════════════════════╡ \n" NOR;
    msg += sprintf(" |%-51s| \n", "");
    return msg;
}

string ob2_cards(object *ob)
{
    string msg;
    msg = " ╞═══════════════════════════════════════════════════╡ \n" NOR;
    msg += sprintf(" |%-51s| \n", "对方手牌状态：未知");
    return msg;
}

string out_area(object *ob_1,object *ob_2)
{
    string msg;
    msg = HIR "≡" HIR"╞═══════════════════════════════════════════════════╡" HIR "≡\n" NOR;
    //msg += print_line(ob2_data->get_summon());
    msg += GRN " ╞═══════════════════════════════════════════════════╡"  "\n" NOR;
    //msg += print_line(env_obj);
    msg += GRN" ╞═══════════════════════════════════════════════════╡"  "\n" NOR;
    //msg += msg += print_ob1_ent(ob_1);
    msg += HIR "≡" HIR "╞═══════════════════════════════════════════════════╡" HIR "≡\n" NOR;
    return msg;
}

string ob1_cards(object *ob)
{
    string msg="";
    //msg = msg += print_ob1_ent(ob);
    msg += " ╞═══════════════════════════════════════════════════╡ \n" NOR;
    return msg;
}
string ob1_equip(object *ob)
{
    string msg="";
    //msg += msg += print_ob1_ent(ob);
    msg += HIC "≡" HIY"╞═══════════════════════════════════════════════════╡" HIC "≡\n" NOR;
    return msg;
}

string ob1_status(object *ob)
{
    string msg="";
    //msg += print_ob1_ent(ob);
    msg += HIC "≡" HIY "└───────────────────────────────────────────────────┘" HIC "≡\n" NOR;
    msg += "请选择出牌顺序（p + 数字0 + 数字1 + .....）注意请用空格分隔数字 \n";
    msg += "<数字x> 为0-9数字，p 后面的每一个数字代表相应的手牌，最多10张 ";
    return msg;
}
