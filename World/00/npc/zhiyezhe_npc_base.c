/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-03 02:22:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-06-03 02:25:40
 * @FilePath: \mysticism-mud\World\00\npc\zhiyezhe_npc_base.c
 * @Description: 职业者小队队员npc 基类
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
