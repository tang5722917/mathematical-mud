/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-30 17:19:41
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-30 17:19:59
 * @FilePath: \mysticism-mud\inherit\camp\camp_base.c
 * @Description: 阵营基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>

// 說明這是一個陣營檔
int isCamp() { return 1; }

// 陣營名稱
string getName() { return ""; }

// 友好陣營
string *getFriendly() { return ({}); }

// 敵對陣營
string *getAdversely() { return ({}); }

// (4) 崇拜, (3) 崇敬, (2) 尊敬, (1) 友好, (0) 中立, (-1) 冷淡, (-2) 敵視, (-3) 敵對, (-4) 仇恨

// 玩家在該陣營的聲望低於多少時會被Auto kill，預設的值是-100
int getHate() { return -101; }

// Auto Kill 時，所要喊的話,$ME為NPC, $YOU為player
string getHateMsg()
{
    return HIR "$ME高声喊道：身為"+getName()+"中的一员，实在是看不惯$YOU的作风！今天就要$YOU消失！\n" NOR;
}

// 玩家在敵對陣營的聲望高於多少時會被Auto kill, 預設的值是 100
int getAdvHate() { return 100; }

// 目對敵對陣營時Auto kill要喊的話, $ME為NPC, $YOU為player
string getAdvHateMsg()
{
    return "";
}
