/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 17:39:39
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 11:27:39
 * @FilePath: \mysticism-mud\World\00\npc\start_up_fight.c
 * @Description: 初始玩家战斗NPC
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <game_world.h>
inherit _LIVING ;

void create()
{
    set_name(YEL "神秘的光团"NOR,({"???"})  );
    set("long", HIC "这是一个神秘的光团，让人无法挪开视线\n可以尝试使用search或sh调查一下" NOR);
    set_visible(0);
    set_fight_living(0);
}

void search(object me,object env)
{
    object ob;
    write("这个光团有着神秘的魅力，你的身体不知不觉的靠近了它\n
这时你的脑海中响起一个声音，“与它战斗吧！\n (使用fight或f命令攻击指定目标，请输入f ???)
不过在这之前请先使用score(sc)查看一下自身状态");
    ob = this_object();
    me->modify_user_status(file_name(ob),3,0);
}

object * fight(object me,object ob)
{
    object *fob = ({this_object()});
    write("神秘光团周围弥漫起了迷雾，并且慢慢变成了一个人的形状
但是无法看清面容\n");
    return fob;
}

string combat_env(object env)
{
    return PATH_00_FIG "start_up_fight";
}

string combat_script(object env,int rank)
{
    return PATH_00_SCR "start_up_fight";
}

string honor_name(object me,object ob)
{
    return "模糊的光团";
}
