/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-03 16:18:43
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-08 18:25:05
 * @FilePath: \mysticism-mud\inherit\living\user_storage.c
 * @Description: 个人物品储存类  -- 操作方法
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit INHERIT_PATH "living/user_storage_base";
#include <bag.h>

mixed get_user_bag(){
    return user_bag;
}

mixed get_user_storage(){
    return user_storage;
}
