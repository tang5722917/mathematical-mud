/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-07 15:40:47
 * @FilePath: \mysticism-mud\inherit\status.c
 * @Description: 玩家状态类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */


protected mapping user_cur_status;

// 设置属性值
mixed set_status(string status, mixed value)
{
    if (!mapp(user_cur_status))
        user_cur_status = ([]);
    return user_cur_status[status] = value;
}

// 获取属性值
mixed query_status(string status)
{
    mixed data;
    if (!mapp(user_cur_status))
        return 0;
    if (undefinedp(user_cur_status[status]))
        return 0;
    data = user_cur_status[status];
    return data;
}

//删除属性
int delete_status(string status)
{
    if (!mapp(user_cur_status))
        return 0;
    else
    {
        map_delete(user_cur_status, status);
        return 1;
    }
}