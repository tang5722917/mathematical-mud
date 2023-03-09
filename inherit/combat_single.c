/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-09 17:34:48
 * @FilePath: \mysticism-mud\inherit\combat_single.c
 * @Description:  单人战斗基类
 *                提供单人战斗的UI
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <ansi.h>
inherit INHERIT_PATH "combat_base";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env;

void create(object o1,object o2,object env)
{
    ob1 = o1;
    ob2 = o2;
    fight_env = env;
}

string fight_init()
{
    return ("你的对手为："+ ob2->short()) ;
}

string ob2_status(object ob2)
{
    string msg;
    msg = HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    return msg;
}

string ob2_equip(object ob2)
{
    string msg;
    msg = " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    return msg;
}

string ob2_cards(object ob2)
{
    string msg;
    msg = " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-50s| \n", "");
    return msg;
}

string out_area()
{
    string msg;
    msg = HIR "≡" HIR "----------------------------------------------------" HIR "≡\n" NOR;
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += GRN " ----------------------------------------------------"  "\n" NOR;
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += GRN" ----------------------------------------------------"  "\n" NOR;
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += sprintf(HIR" |"NOR "%-50s"HIR"|"NOR "\n", "");
    msg += HIR "≡" HIR "----------------------------------------------------" HIR "≡\n" NOR;
    return msg;
}

string ob1_cards(object ob1)
{
    string msg;
    msg = sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-50s| \n", "");
    msg += " |--------------------------------------------------| \n" NOR;
    return msg;
}
string ob1_equip(object ob1)
{
    string msg;
    msg = sprintf(" |%-50s| \n", "");
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    return msg;
}
string ob1_status(object ob1)
{
    string msg;
    msg = sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-50s| \n", "");
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += "请选择出牌顺序（p + 数字1 + 数字2 + .....）注意请用空格分隔数字";
    return msg;
}

string fight_main_UI(int fight_time,int fight_round)
{
    string msg;
    msg = "第" + fight_round + "回合   |地点："+fight_env->short()+"\n";
    msg += ob2_status(ob2);
    msg += ob2_equip(ob2);
    msg += ob2_cards(ob2);
    msg += out_area();
    msg += ob1_cards(ob1);
    msg += ob1_equip(ob1);
    msg += ob1_status(ob1);
    return msg;
}

void print_fight(string msg)
{
    message("FIG",msg,ob1);
}


object get_player1()
{
    return ob1;
}

