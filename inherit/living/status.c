/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 11:56:44
 * @FilePath: \mysticism-mud\inherit\living\status.c
 * @Description: 玩家状态类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
//            0  ->  8
//| VISIBLE | FIGHT | Get |
#define VISIBLE 1   //不可见的object可见
#define FIGHT   3   //不可战斗的object可以战斗
#define GET     7  //不可获取的object可以获取

protected mapping user_cur_status;
protected nosave mapping temp_user_cur_status;

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

// 设置属性值
mixed set_status(string status, mixed value)
{
    int t;
    if (!mapp(user_cur_status))
        user_cur_status = ([]);
    t = query_status(status);
    return user_cur_status[status] = t | value;
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

// 获取临时属性值
mixed temp_query_status(string status)
{
    mixed data;
    if (!mapp(temp_user_cur_status))
        return 0;
    if (undefinedp(temp_user_cur_status[status]))
        return 0;
    data = temp_user_cur_status[status];
    return data;
}

// 设置临时属性值
mixed temp_set_status(string status, mixed value)
{
    int t;
    if (!mapp(temp_user_cur_status))
        temp_user_cur_status = ([]);
    t = temp_query_status(status);
    return temp_user_cur_status[status] = t | value;
}

//删除临时属性
int temp_delete_status(string status)
{
    if (!mapp(temp_user_cur_status))
        return 0;
    else
    {
        map_delete(temp_user_cur_status, status);
        return 1;
    }
}

mixed modify_user_status(string status_name,int value,int type)
{
    object me=this_player();
    if (type)
        return me->set_status(status_name, value);
    else
        return me->temp_set_status(status_name, value);
}
