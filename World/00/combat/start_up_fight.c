/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 19:10:25
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <game_world.h> 

inherit CORE_STD_FIGHT_S;

int fight_init_user(object user)
{   
    add_f_info("同时脑海中有一个清晰的声音响起——“你要准备开始战斗”",user);
}

int fight_init_env(object env)
{
    add_f_info("模糊的人影抬起头注视着你",env);
}

int fight_end_user(object user)
{
    add_f_info("又感到一阵眩晕",user);
}

//定义电脑的战斗结束时行为
int fight_end_env(object env)
{
    add_f_info("身影缓缓消失",env);
}

// 定义战斗胜利后的奖励与剧情
void end_event(object result_ob,object user)
{
    msg_end();
    if(result_ob->get_result() == 1)
    {
        fight_env->newbie_choice(user);
    }
}
