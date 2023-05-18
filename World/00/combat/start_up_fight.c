/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-18 19:43:03
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <game_world.h> 
#include <task.h>
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
//进行角色出生身份选择
void newbie_choice(object ob)
{
    string str;     
    mixed ch = ({});
    str  = "昏昏沉沉间你好像想起一点东西。\n";
    ob->add_choice_title_info(str);
    str = "    请选择你的出生地点：\n";
    ch += ({str});
    str = "    0  鲁恩 -- 廷根\n";
    ch += ({({str,0})});
    ob->add_choice(ch);
    str  = "    请选择你信仰的神灵：\n";
    ch  = ({str});
    str = "    0  黑夜女神\n";
    ch += ({({str,0})});
    ob->add_choice(ch);
}

// 定义战斗胜利后的奖励与剧情
void end_event(object result_ob,object user)
{
    object ob = new(TASK_CHOICE);
    msg_end();
    if(result_ob->get_result() == 1)
    {
        ob->init(user);
        newbie_choice(ob);
        ob->start();
    }
}
