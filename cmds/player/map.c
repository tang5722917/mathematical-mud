/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-04-22 16:44:05
 * @FilePath: \mysticism-mud\cmds\player\map.c
 * @Description: 显示区域地图
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <map.h> 
#include <game_world.h> 
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    string str;
    object ob = load_object(MAP_SHOW_D);
    str = ob->show_map(me);
    if(stringp(str))
        write( str );
    else write( "当前区域无地图" );
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: map
显示当前区域地图信息
HELP );
        return 1;
}
