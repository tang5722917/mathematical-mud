/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-20 19:55:12
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-04 17:07:53
 * @FilePath: \mysticism-mud\World\include\card.h
 * @Description: CARD 定义头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#ifndef CARD_H
#define CARD_H

#include <ansi.h>
#include <mxp.h>
#include <game_world.h>
inherit CORE_STD_CARD;

//定义Card执行效果类型
#define CBUFF1    1           //给予己方状态BUFF
#define CBUFF2    2           //给予对方状态BUFF
#define CSUMMON   3           //召唤物品
#define CATTACK1  4           //完成物理HP攻击
#define CATTACK2  5           //完成非凡HP攻击
#define CVALUE1   6           //对己方的属性进行改变
#define CVALUE2   7           //对对方的属性进行改变

#endif //CARD_H
