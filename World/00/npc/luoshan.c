/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-28 03:11:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-29 16:39:25
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

void event_wellcome_user(object ob,object me){
    string str;
    str = honor_name(this_object(),me) + " 欢迎回来";
    TASK_S->npc_tell(me,str,this_object());
}
