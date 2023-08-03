/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-14 20:03:40
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-03 20:15:53
 * @FilePath: \mysticism-mud\World\base\room\shop\grocery_base.c
 * @Description: 小型杂货铺基类
 *               只有一个小型商店 + 1个店员
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <build_module.h>

inherit MYSTIC_ROOM "shop/base/shop_small_base";

void shop_init()
{
    object paizi = new(Paizi);
    paizi->move(this_object());
}
