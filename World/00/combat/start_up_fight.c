/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-14 17:52:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-17 02:14:12
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <game_world.h> 

#define First_ROOM PATH_00_MAP "1/0_0_1"
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
    debug_message( sprintf("%O",this_player() ));
    if(result_ob->get_result()== 1)
        user->move(First_ROOM);
}
