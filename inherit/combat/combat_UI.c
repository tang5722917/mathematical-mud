/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-31 19:17:44
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI.c
 * @Description: 战斗的基础类
 *               具体战斗继承该类
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
inherit INHERIT_PATH "combat/combat_base";
#define USER 0
#define ENV 1

//战斗过程颜色控制
string * print_color_fig(string * str,int type)
{
    string s;
    int n;
    n = sizeof(str);
    if(n == 0)
        return 0;
    if(type == USER )
    {
        for(int i =0;i < n ;i++)
        {
            s = str[i];
            s = GRN + s + NOR;
            str[i] = s;
        } 
        return str;
    }
    if(type == ENV )
    {
        for(int i =0;i < n ;i++)
        {
            s = str[i];
            s = RED + s + NOR;
            str[i] = s;
        } 
        return str;
    }
    return 0;
}

string print_line(object *ob)
{
    int num = sizeof(ob);
    int line_num = num / 6;
    string *str=allocate(6,"");
    if(num == 0)
        return sprintf(" |%-50s| \n", "");
    else
    {
        return sprintf(" |%-9s%-8s%-8s%-8s%-8s%-9s| \n", str[0], str[1], str[2], str[3], str[4], str[5]);
    }
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
    msg += sprintf(" |%-50s| \n", "对方手牌状态：未知");
    return msg;
}

string out_area()
{
    string msg;
    msg = HIR "≡" HIR "----------------------------------------------------" HIR "≡\n" NOR;
    msg += print_line(ob2_summon);
    msg += GRN " ----------------------------------------------------"  "\n" NOR;
    msg += print_line(env_obj);
    msg += GRN" ----------------------------------------------------"  "\n" NOR;
    msg += print_line(ob1_summon);
    msg += HIR "≡" HIR "----------------------------------------------------" HIR "≡\n" NOR;
    return msg;
}

string ob1_cards(object ob1)
{
    string msg;
    msg = print_line(ob1_card);
    msg += " |--------------------------------------------------| \n" NOR;
    return msg;
}
string ob1_equip(object ob1)
{
    string msg;
    msg = print_line(ob1_equip);
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    return msg;
}

string ob1_status(object ob1)
{
    string msg;
    msg = sprintf(" |%-22s%-14s%-14s| \n", ob1->short(),"血气"+ob1->query_attr("hp")+"/"+ob1->query_attr("max_hp")
    ,"精力"+ob1->query_attr("mp")+"/"+ob1->query_attr("max_mp"));
    msg += print_line(ob1_status);
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += "请选择出牌顺序（p + 数字0 + 数字1 + .....）注意请用空格分隔数字 \n";
    msg += "<数字x> 为0-9数字，p 后面的每一个数字代表相应的手牌，最多10张 ";
    return msg;
}
