/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:15:58
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-22 19:22:46
 * @FilePath: \mysticism-mud\inherit\living\status_task_days.c
 * @Description: 用于记录管理玩家日常任务（可重复进行）
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <task_main_version.h>

protected mapping user_task_day; 

void init_user_task_days()
{
    if(mapp(user_task_day))
        user_task_day = ([]);
}
