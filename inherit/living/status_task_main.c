/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:15:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-19 18:13:52
 * @FilePath: \mysticism-mud\inherit\living\status_task_main.c
 * @Description: 用于记录管理玩家主线任务（只能进行一次）
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <task_main.h>

inherit  PATH_00_TAK "main_task_00";
protected mapping user_task_main;    //存储正在进行的task

void init_user_task_main()
{
    object task_d;
    task_d = load_object(INHERIT_PATH "living/living_d/status_task_d");
    if(!mapp(user_task_main))
        user_task_main = ([]);
    
    main_task_00_init();
}

int add_task(object task)
{
    if(sizeof(user_task_main) == MYSTIC_MAX_QUEST){
        write("做事要一心一意，接受这么多的任务你干的过来吗！");
        return 0;
    }
}
