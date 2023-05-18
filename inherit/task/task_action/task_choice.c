/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 19:45:39
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-18 09:18:45
 * @FilePath: \mysticism-mud\inherit\task\task_action\task_choice.c
 * @Description:  用于实现任务中的选项动作
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

string confirm_info;
object user;

void init(object user)
{
    user = user;
    confirm_info = "";
}

void add_choice(string str,int * ch)
{

}

void add_choice_confirm(string str)
{
    
}

string confirm_info() {
    return confirm_info;
}
