/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-14 18:39:59
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI_single.c
 * @Description: 提供单人战斗的UI
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
#include  <combat.h>
inherit INHERIT_PATH "combat/combat_UI";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env,script;

//战斗过程颜色控制
string print_color_fig(F_INFO str,int type)
{
    string s;
    int n;
    if(str == 0)
        return 0;
    if(type == USER )
    {
        s = str->str;
        s = GRN + "你："+ s + NOR;
        return s;
    }
    if(type == ENV )
    {
        s = str->str;
        s = RED +str->ob1->id_list()[0] +"："+ s + NOR;
        return s;
    }
    if(type == COM )
    {
        s = str->str;
        s = BYEL + s + NOR;
        return s;
    }
    return 0;
}

void print_fight(F_INFO msg)
{
    int type;
    if(msg->ob1 == 0)
        type = COM;
    else if(msg->ob1 == ob1)
        type = USER;
    else if(msg->ob1 == ob2)
        type = ENV;
    message("FIG",print_color_fig(msg,type),ob1);
}
