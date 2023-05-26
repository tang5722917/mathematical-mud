/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 19:52:51
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-26 18:08:41
 * @FilePath: \mysticism-mud\inherit\task\task_action\task_story.c
 * @Description: 任务中的剧情环节
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

//开始剧情输出
varargs void start_task_story(object user,string *str,object des,object entity,object other)
{
    user->disable_command();
    foreach(string s in str)
    {
        user->add_user_info(s,des);
    }
}
 
