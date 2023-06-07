/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-03 02:26:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-06-07 07:28:48
 * @FilePath: \mysticism-mud\World\00\npc\dengeng.c
 * @Description: 廷根职业小队队长-邓恩 斯密斯
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h>
#include <game_00.h>
#include <ansi.h>
inherit ZHIYEZHE;
void create()
{
    ::create();
    set_name(WHT "邓恩.史密斯" NOR,({"dengeng"})  );
    set("long", HIC "穿着黑色风衣高礼帽,有着深邃冷漠的灰色眼眸和很高的发际线" NOR);
}
 
void event_wellcome_user(object ob,object me){
    string str;
    str = honor_name(this_object(),me) + " 你有什么事找我吗？";
    TASK_S->npc_tell(me,str,this_object());
}

answer(object user,object env)
{
    {write("你可以向我提出以下问题：
task    -  关于廷根职业者任务。
skill   -  关于廷根职业者能够学习的技能。
mysticism -黑夜教会掌握的非凡途径。
live     - 职业者的日常生活
faith    - 黑夜教会信仰\n ");}
}
