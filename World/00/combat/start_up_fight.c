/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-14 17:52:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 16:26:43
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <game_world.h> 
inherit CORE_STD_FIGHT_S;

string * fight_init_user(object user)
{   
    string * str=({});
    str +=({"突然感觉体内涌现一股神秘的力量！"});
    str +=({"同时脑海中有一个清晰的声音响起——“你要准备开始战斗”"});
    return str;
}

string * fight_init_env(object env)
{
    string * str=({});
    str +=({"模糊的人影抬起头注视着你"});
    return str;
}

string * fight_end_user(object user)
{
    return ({"你感到身上的力量衰退了\n"});
    return 0;
}
