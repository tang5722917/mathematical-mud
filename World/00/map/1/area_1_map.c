/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-23 19:15:28
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-23 19:19:22
 * @FilePath: \mysticism-mud\World\00\map\1\area_1_map.c
 * @Description: 廷根女神教区一些公共函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <world_map.h>
#define AREA_1_OB AREA_1 "area_1"

inherit CORE_STD_ROOM;

void show_map_info(object user){
    message("MAP",load_object(AREA_1_OB)->get_area_map(),user);
}
