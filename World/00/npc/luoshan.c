/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-28 03:11:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-28 16:42:50
 * @FilePath: \mysticism-mud\World\00\npc\luoshan.c
 * @Description: 黑荆棘安保公司 - 罗珊小姐
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <game_00.h>
#include <ansi.h>
inherit CITIZEN_0;

void create()
{
    ::create();
    set_name(WHT "罗珊" NOR,({"luoshan"})  );
    set("long", HIC "热情开朗的棕发女孩" NOR);
}

void wellcome_user(object me){
    msg("info","欢迎回来",me);
}
