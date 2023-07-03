/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-03 02:22:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-03 14:48:21
 * @FilePath: \mysticism-mud\World\00\npc\zhiyezhe_npc_base.c
 * @Description: 职业者小队队员npc 基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
inherit  CORE_STD_PERSON_NPC;
protected void create()
{
    set_name(WHT "职业者" NOR,({"zhiyezhe"})  );
    set("long", HIC "隶属于黑夜教会，负责处理教会教区内的非凡事件" NOR);
    living_setup();
} 
