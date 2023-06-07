/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-16 19:30:32
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-06-07 08:06:52
 * @FilePath: \mysticism-mud\World\00\map\1\map_0_0_3.c
 * @Description: 廷根 黑夜教会/职业小队地图 - 队长办公室
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
#include <world_map.h>
#include "area_1.h"
inherit AREA_1 "area_1_map";
 
 void create()
 {
     set("short", "队长办公室");
     set("long", "\n");
     set("dq", 1); // 设置所属世界
     set("outdoors", 0); // 设置是否户外
     setArea(1, 0, 0, 3,"黑荆棘安保公司"); // 设置所属地区和x,y,z坐标
     set("no_get", 0); // 是否禁止拾起
     set("no_drop", 0); // 是否禁止丢弃
     set("no_fight", 1); // 是否禁止战斗
     set("no_sleep",0);   //是否可以休息
     set("exits",([ 
        "south" : PATH_00_MAP "1/map_0_0_2"
     ]));
     set("objects",([
        
     ]));
 
     setup();
 }

 void event_enter(object user){
    if(userp(user))
        NPC_OB(dengeng_ob)->event_wellcome_user(this_object(),user);
}
