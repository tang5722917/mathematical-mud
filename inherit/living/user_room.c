/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-16 19:16:49
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-16 19:22:00
 * @FilePath: \mysticism-mud\inherit\living\user_room.c
 * @Description: 独属user的room 属性
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

//记录属于玩家的room信息
mapping room_info;

int home_check_access(object env)
{
    return 1;
}
