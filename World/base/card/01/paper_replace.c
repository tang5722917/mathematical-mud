/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:06:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 19:16:48
 * @FilePath: \mysticism-mud\World\base\card\01\paper_replace.c
 * @Description:  纸人替身牌
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#include <card.h>

 string card_name(){return "空气子弹";}
 string card_short(){return "通过空气子弹来攻击敌人，子弹的威力取决于灵性";}
//1-card 01-对应非凡途径序号1占卜家 8-小丑 01编号
int card_id(){return 101801;}

//卡片类型： 召唤
int *perform_type(){return ({CSUMMON});}
