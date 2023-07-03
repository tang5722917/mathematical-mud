/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-28 02:04:38
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-03 14:53:50
 * @FilePath: \mysticism-mud\World\00\npc\chefu_1.c
 * @Description: 普通市民基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 #include <game_world.h>
 #include <game_00.h>
 #include <ansi.h>
 inherit CITIZEN_0;

protected void create()
{
    set_name(WHT "车夫马车" NOR,({"chefu"})  );
    set("long", HIC "普通的一个市民" NOR);
    living_setup();
} 
