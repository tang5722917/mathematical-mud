/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-24 19:20:01
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
    object ob = load_object(MAP_SHOW_D);
    write( ob->show_map(me));
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
