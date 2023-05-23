/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-04 18:19:34
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-23 09:06:57
 * @FilePath: \mysticism-mud\World\00\task\main_task_00.c
 * @Description:  00_主线任务
 * 
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */
#include <game_world.h>
protected mapping main_task_00; 
nosave protected object main_task_list_00;

void main_task_00_init()
{
    if(!mapp(main_task_00))
        main_task_00 = ([]);
    main_task_list_00 = load_object(PATH_00_TAK "main_task_d_00");
}
