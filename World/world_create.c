/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-04 18:27:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 11:43:38
 * @FilePath: \mysticism-mud\World\world_create.c
 * @Description: 
 * 
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <game_world.h> 

void init_daemons()
{
    new(FIGHT_D,0,0);
}

void init_base()
{
    load_object(PATH_BASE "world_base_create.c");
}
void init_00()
{
    load_object(PATH_00 "world_00_create.c");
}


int create()
{
    version_str_to_int( World_version );
    debug_message("[" + ctime() + "]世界地图开始加载\n");
    //加载基础组件
    //非凡特性/状态/物品 etc
    init_daemons();
    init_base();
    //加载版本地图
    init_00();
}
