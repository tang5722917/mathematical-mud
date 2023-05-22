/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-04 18:19:34
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-22 19:37:57
 * @FilePath: \mysticism-mud\World\00\task\day_task_00.c
 * @Description:  00_日常任务
 * 
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */
#include <game_world.h>
 protected mapping day_task_00; 
 nosave protected object day_task_list_00;
 
 void init()
 {
     if(mapp(day_task_00))
        day_task_00 = ([]);
    day_task_list_00 = load_object(PATH_00_TAK "day_task_d_00");
 }
