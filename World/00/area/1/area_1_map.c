/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-23 19:15:28
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-28 15:32:39
 * @FilePath: \mysticism-mud\World\00\area\1\area_1_map.c
 * @Description: 廷根女神教区一些公共函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <world_map.h>
#include "../../map/1/area_1.h"

inherit CORE_STD_ROOM;

object get_area_ob(){return find_object(AREA_1_OB);}

void show_map_info(object user){
    message("MAP",get_area_ob()->get_area_map(),user);
}

mixed *get_map_info(){
    return get_area_ob()->get_area_room_obs();
}
