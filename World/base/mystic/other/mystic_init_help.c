/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-21 01:36:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 15:27:23
 * @FilePath: \mysticism-mud\World\base\mystic\other\mystic_init_help.c
 * @Description:  初始新手指引中的非凡特性
 *                用于新手指引与测试开发
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

inherit CORE_STD_MYSTIC;
//非凡特性编号
void create()
{
    mystic_num=100;
 //序列等级 0-9
    mystic_rank=10;
}
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
