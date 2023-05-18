/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-18 09:19:46
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
    str  = "昏昏沉沉间你好像想起一点东西。";
    str += "    请选择你的出生地点：";
    str += "----------------------------\n";
    str += "    0  鲁恩 -- 廷根";
    str += "----------------------------\n";
    ob->add_choice(str,({0}));
    str  = "    请选择你信仰的神灵：";
    str += "----------------------------\n";
    str += "    1  黑夜女神";
    str += "----------------------------\n";
    ob->add_choice(str,({1}));
}
//选择确认
void choice_confirm(object ob)
{
    string str;
    str  = "----------------------------\n";
    str += "请确认你的选择，输入Y（y）表示确认\n";
    str += "你的选择为"+ob->confirm_info()+"\n";
    str += "----------------------------\n";
    ob->add_choice_confirm(str);
    return ;
}
// 定义战斗胜利后的奖励与剧情
void end_event(object result_ob,object user)
{
    object ob = new(TASK_CHOICE);
    string str;
    msg_end();
    if(result_ob->get_result() == 1)
    {
        ob->init(user);
        choice_confirm(ob);
        newbie_choice(ob);
    }
}
