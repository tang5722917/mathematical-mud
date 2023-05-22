/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:15:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-22 19:21:01
 * @FilePath: \mysticism-mud\inherit\living\status_task_main.c
 * @Description: 用于记录管理玩家主线任务（只能进行一次）
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <task_main_version.h>

protected mapping user_task_main; 

void init_user_task_main()
{
    object task_d;
    task_d = load_object(INHERIT_PATH "living/living_d/status_task_d");
    if(mapp(user_task_main))
        user_task_main = ([]);
    task_d->init_user_task(this_object());
}
