/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-03 16:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-18 04:46:10
 * @FilePath: \mysticism-mud\inherit\living\user_storage_base.c
 * @Description: 个人物品存储 基类 - 存档数据结构
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

mixed *user_storage;  // 仓库
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
