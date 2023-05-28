/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-28 02:04:38
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-28 03:40:05
 * @FilePath: \mysticism-mud\World\00\npc\citizen_base.c
 * @Description: 普通市民基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
inherit  CORE_STD_PERSON_NPC;

protected void create()
{
    set_name(WHT "普通市民" NOR,({"citizen"})  );
    set("long", HIC "普通的一个市民" NOR);
    living_setup();
} 
