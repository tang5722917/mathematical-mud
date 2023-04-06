/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:44:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-06 19:42:39
 * @FilePath: \mysticism-mud\system\daemons\time_d.c
 * @Description: 时间守护进程 继承自mudcore  CORE_TIME_D
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit CORE_TIME_D;
#include <ansi.h>
#include <localtime.h>
#include <game_world.h>

//根据诡秘中的日期计算周几
//6/18 周一为起点
int cal_week_game_time(int *localtime)
{
    int days;
    return 1;
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
    localtime[LT_MDAY] = World_day-1;
    localtime[LT_WDAY] =cal_week_game_time(localtime);
    return localtime;
}

varargs string game_time_description(string arg, int style)
{
    if (!arg)
        arg = "第五纪元";

    return time_description(arg, query_game_time(), style);
}
