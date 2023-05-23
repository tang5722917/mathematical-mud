/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:15:58
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-23 03:11:36
 * @FilePath: \mysticism-mud\inherit\living\status_task_days.c
 * @Description: 用于记录管理玩家日常任务（可重复进行）
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <task_day.h>

inherit  PATH_00_TAK "day_task_00";

protected mapping user_task_day; 

void init_user_task_days()
{
    object task_d;
    task_d = load_object(INHERIT_PATH "living/living_d/status_task_d");
    if(!mapp(user_task_day))
        user_task_day = ([]);
    
    day_task_00_init();
}
