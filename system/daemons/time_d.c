/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:44:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-07 10:37:18
 * @FilePath: \mysticism-mud\system\daemons\time_d.c
 * @Description: 时间守护进程 继承自mudcore  CORE_TIME_D
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit CORE_TIME_D;
#include <ansi.h>
#include <localtime.h>
#include <game_world.h>

int cal_mon_days(int *localtime){
    int mon_days=0;
switch(localtime[LT_MON]-1)
{
    case 11:mon_days += 31;
    case 10:mon_days += 30;
    case 9:mon_days += 31;
    case 8:mon_days += 30;
    case 7:mon_days += 31;
    case 6:mon_days += 31;
    case 5:mon_days += 30;
    case 4:mon_days += 31;
    case 3:mon_days += 30;
    case 2:mon_days += 31;
    case 1:mon_days += 28;
    case 0:mon_days += 31;
}
return mon_days;
}
//根据诡秘中的日期计算周几
//  1349/6/18 周一为起点
int cal_week_game_time(int *localtime)
{
    int days;
    days = cal_mon_days(localtime)-151+localtime[LT_MDAY];
    days -= 17;
    return days%7;
}

// 重新定义game_time含义
// 时/分同真实时间
// 日期由游戏版本决定
int *game_localtime(int timestamp)
{
    int *localtime;
    // 设置游戏localtime
    localtime = analyse_time(timestamp);
    localtime[LT_YEAR] = World_year; 
    localtime[LT_MON] = World_month-1;
    localtime[LT_MDAY] = World_day;
    localtime[LT_WDAY] =cal_week_game_time(localtime);
    return localtime;
}

varargs string game_time_description(string arg, int style)
{
    if (!arg)
        arg = "第五纪元 ";

    return time_description(arg, query_game_time(), style);
}
