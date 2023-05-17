/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-16 19:30:32
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-17 02:00:09
 * @FilePath: \mysticism-mud\World\00\map\1\0_0_1.c
 * @Description: 廷根 黑夜教会/职业小队地图 - 炼金室
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
 
 inherit CORE_STD_ROOM;
 
 void create()
 {
     set("short", "炼金室");
     set("long", "四周弥漫着灰雾，朦胧、模糊、无边无际。\n    耳畔想起了时而细密，时而尖锐，时而虚幻，时而诱人，时而狂躁，时而疯癫的低语
     前方好像有一个模糊的人影。你想仔细看，但由于灰雾的笼罩没办法看清\n(可以使用look或l命令来进一步查看(例如:l ?????))");
     set("dq", 1); // 设置所属世界
     set("outdoors", 0); // 设置是否户外
     setArea(0, 0, 0, 1,"黑荆棘安保公司"); // 设置所属地区和x,y,z坐标
     set("no_get", 1); // 是否禁止拾起
     set("no_drop", 1); // 是否禁止丢弃
     set("no_fight", 1); // 是否禁止战斗
     set("objects",([
     ]));
 
     setup();
 }
