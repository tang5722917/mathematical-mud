/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-06 10:33:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-21 15:23:55
 * @FilePath: \mysticism-mud\World\00\world_00_create.c
 * @Description: 0.x 版本内容预加载
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
inherit CORE_STD_PRE;

string ob_name()
{
    return "0.x版本游戏资源对象";
}

 void create()
 {
    ::create();
    load_path_object(PATH_00_MYH);
    load_path_object(PATH_00_SCR);
    load_path_object(PATH_00_STA);
    //load_path_object(PATH_00_PRO);
    //load_path_object(PATH_00_MAP);
    ob_load_end(1);
 }
