/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-21 01:36:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 18:46:59
 * @FilePath: \mysticism-mud\World\00\mystic\mystic_init_fight.c
 * @Description:  初始新手指引中敌人的非凡特性
 *                用于新手指引与测试开发
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h> 
inherit CORE_STD_MYSTIC;
//非凡特性编号101
int rank_num()
{
    return 101;
}
//序列等级10
int mystic_rank()
{
    return 10;
}

//非凡特性名称
string mystic_name(){return "???";}
//非凡特性short 介绍
string mystic_short(){return "感觉拥有神秘的力量";}

//定义非凡特性对数值的影响
//hp
int hp_val(){return 50;}
//mp
int mp_val(){return 100;}
//str
int str_val(){return 30;}
//agi
int agi_val(){return 30;}
//sen
int sen_val(){return 30;}
//int
int cra_val(){return 10;}
//cra
int luk_val(){return 5;}
//luk
int mys_val(){return 0;}

void create()
{
    mystic_card(MYSTIC_CARD "12/fire_ball");
}
