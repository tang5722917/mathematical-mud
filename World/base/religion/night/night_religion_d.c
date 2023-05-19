/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-19 19:23:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 19:31:23
 * @FilePath: \mysticism-mud\World\base\religion\night\night_religion_d.c
 * @Description: 黑夜教会 常用函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>

//新人初始房间
#define First_ROOM PATH_00_MAP "1/0_0_1"
// 新人初始化

void newbie_init(object user)
{
    user->move(First_ROOM);
}
