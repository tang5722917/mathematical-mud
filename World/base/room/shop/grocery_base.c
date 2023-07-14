/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-14 20:03:40
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-14 20:06:28
 * @FilePath: \mysticism-mud\World\base\room\shop\grocery_base.c
 * @Description: 小型杂货铺基类
 *               只有一个小型商店 + 1个店员
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit "./base/shop_small_base";

void init_grocery(string name,string describe,int world)
{
    set("short", name);
    set("long", describe );
    set("dq", world); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(1, 0, 0, 1,"黑荆棘安保公司"); // 设置所属地区和x,y,z坐标
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
    set("no_sleep",0);   //是否可以休息
    set("exits",([ 
       "out" : PATH_00_MAP "1/map_0_0_2"
    ]));
    set("objects",([

    ]));

    setup();
}
