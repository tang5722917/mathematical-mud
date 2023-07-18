/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-16 19:04:22
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-18 05:08:20
 * @FilePath: \mysticism-mud\World\base\room\lodging\lodging_init.c
 * @Description:  user宿舍初始化
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
#include <world_map.h>
nosave object init_room;
//user 宿舍room初始化

void room_init()
{
    object lodging_area;
    lodging_area = new(LODGING "lodging_area");
    init_room = lodging_area->init_room();
}

object init_room()
{
    return init_room;
}
