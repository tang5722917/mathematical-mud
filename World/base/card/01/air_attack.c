/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:08:22
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 18:57:48
 * @FilePath: \mysticism-mud\World\base\card\01\air_attack.c
 * @Description:  空气炮
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <card.h>

string card_name(){return "纸人替身";}
string card_short(){return "放置一个生命为1的纸人，抵挡一次攻击";}
//1-card 01-对应非凡途径序号1占卜家 7-魔术师 01编号
int card_id(){return 101701;}

//卡片类型： 单体攻击
int *perform_type(){return ({CATTACK1});}
