/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-06 16:15:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-06 16:16:59
 * @FilePath: \mysticism-mud\inherit\living\status_task_main.c
 * @Description: 用于记录管理玩家主线任务（只能进行一次）
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

protected mapping user_task_main; 

varargs init_user_task_main(mapping m)
{
    if(mapp(m))
        user_task_main = m;
    else
        user_task_main = ([]);
}
