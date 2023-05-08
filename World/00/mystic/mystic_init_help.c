/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-21 01:36:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 15:17:14
 * @FilePath: \mysticism-mud\World\00\mystic\mystic_init_help.c
 * @Description:  初始新手指引中的非凡特性
 *                用于新手指引与测试开发
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved.
 */
#include <game_world.h> 
inherit CORE_STD_MYSTIC;
//非凡特性编号100
int rank_num()
{
    return 100;
}
//序列等级10
int mystic_rank()
{
    return 10;
}

//非凡特性名称
string mystic_name(){return "????";}
//非凡特性short 介绍
string mystic_short(){return "感觉身体中有一股莫名其妙的力量";}

//定义非凡特性对数值的影响
//hp
int hp_val(){return 100;}
//mp
int mp_val(){return 50;}
//str
int str_val(){return 20;}
//agi
int agi_val(){return 20;}
//sen
int sen_val(){return 20;}
//int
int cra_val(){return 10;}
//cra
int luk_val(){return 5;}
//luk
int mys_val(){return 5;}

void create()
{
    mystic_card(MYSTIC_CARD "01/air_attack");
    mystic_card(MYSTIC_CARD "01/paper_replace");
}
