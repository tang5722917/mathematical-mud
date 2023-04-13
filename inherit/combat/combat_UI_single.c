/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-13 18:55:09
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI_single.c
 * @Description: 提供单人战斗的UI
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
#include  <combat.h>
inherit INHERIT_PATH "combat/combat_UI";


//战斗过程颜色控制
mixed * print_color_fig(mixed * str,int type)
{
    string s;
    int n;
    mixed *tr;
    n = sizeof(str);
    if(n == 0)
        return 0;
    if(type == USER )
    {
        for(int i =0;i < n ;i++)
        {
            tr = str[i];
            s = tr[0];
            s = GRN + "你："+ s + NOR;
            tr[0] = s;
        } 
        return str;
    }
    if(type == ENV )
    {
        for(int i =0;i < n ;i++)
        {
            tr = str[i];
            s = tr[0];
            s = RED +tr[1]->id_list()[0] +"："+ s + NOR;
            tr[0] = s;
        } 
        return str;
    }
    return 0;
}
