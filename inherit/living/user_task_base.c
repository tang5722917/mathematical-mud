/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-18 15:05:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-20 18:50:53
 * @FilePath: \mysticism-mud\inherit\living\user_task_base.c
 * @Description: 与任务有关的一些基本支持
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object task_choice;

void task_choice_start(object ch_ob)
{
    this_object()->set_choice_command(-1);
    task_choice = ch_ob;
}

void input_choice_command(int in_num)
{
    if(task_choice->choice_item(in_num))
        task_choice->choice_next_item();
    else task_choice->choice_item_again();
}

int is_choice_confirm(){
    return task_choice->is_choice_confirm();
}

int choice_confirm()
{
    if(objectp(task_choice))
        if(task_choice->is_confirm())
        {
            task_choice->task_confirm();
            return 1;
        }
}
