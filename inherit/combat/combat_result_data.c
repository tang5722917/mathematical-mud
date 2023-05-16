/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-16 16:00:29
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 16:00:35
 * @FilePath: \mysticism-mud\inherit\combat\combat_result_data.c
 * @Description: 战斗结果数据类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

protected object *user1,*user2;
//1 - user1胜利 /2 - user2胜利 /3 - 平局
protected int result;

int set_result(int r){result = r;}
int get_result(){return result;}
