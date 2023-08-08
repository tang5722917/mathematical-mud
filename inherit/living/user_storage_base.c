/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-03 16:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-08 18:24:47
 * @FilePath: \mysticism-mud\inherit\living\user_storage_base.c
 * @Description: 个人物品存储 基类 - 存档数据结构
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

//每个元素：{string obj, int num, class position}
#include <bag.h>
mixed *user_storage;  // 仓库
//每个元素：{string obj, int num, class carry_status}
mixed *user_bag;      //玩家携带

void bag_storage_init()
{
    if(!arrayp(user_storage))
        user_storage = ({});
    if(!arrayp(user_bag))
        user_bag = ({
            ({"base_bag"})
        });
}
