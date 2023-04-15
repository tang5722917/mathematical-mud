/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-14 17:52:37
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-04-15 15:30:08
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <game_world.h> 
inherit CORE_STD_FIGHT_S;

int fight_init_user(object user)
{   
    add_f_info("突然感觉体内涌现一股神秘的力量！",user);
    add_f_info("同时脑海中有一个清晰的声音响起——“你要准备开始战斗”",user);
}

int fight_init_env(object env)
{
    add_f_info("模糊的人影抬起头注视着你",env);
}

int fight_end_user(object user)
{
    add_f_info("感到身上的力量衰退了",user);
}

//定义电脑的战斗结束时行为
int fight_end_env(object env)
{
    add_f_info("身影缓缓消失",env);
}
