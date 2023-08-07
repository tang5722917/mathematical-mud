/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-16 19:30:32
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-07 17:51:38
 * @FilePath: \mysticism-mud\World\00\map\1\map_0_0_10.c
 * @Description: 廷根 黑夜教会/职业小队地图 - 杂货铺
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
#include <world_map.h>
#include "area_1.h"
inherit AREA_1 "area_1_map";
inherit SHOP_S;

string kente_grocery_paizi=@GROCERY
本店出售日用食品。
支持指令:
GROCERY ;

string * kente_grocery_cmds=({"list","buy"});

void create()
{
    set("short", "肯特杂货铺");
    set("long", "街道旁有一家小杂货铺，出售一些日常用品与食物。
周围的居民购买用品的小店，价格比较便宜。\n");
    set("dq", 1); // 设置所属世界
    set("outdoors", 1); // 设置是否户外
    setArea(1, 0, 0, 10,"杂货铺"); // 设置所属地区和x,y,z坐标
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
    set("no_sleep",0);   //是否可以休息
    set("exits",([ 
       "east" : PATH_00_MAP "1/map_0_0_7"

    ]));
    set("objects",([
    ]));
    setup();
    shop_init(kente_grocery_paizi,kente_grocery_cmds,"kente");
}
