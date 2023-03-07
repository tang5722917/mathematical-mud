/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-04 18:27:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-07 10:25:04
 * @FilePath: \mysticism-mud\World\world_create.c
 * @Description: 
 * 
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <game_world.h> 

object *world_map;

int create()
{
    version_str_to_int( World_version );
    debug_message("[" + ctime() + "]世界地图开始加载\n");

}