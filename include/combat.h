/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 14:18:47
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 17:09:05
 * @FilePath: \mysticism-mud\include\combat.h
 * @Description: 战斗相关头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#ifndef COMBAT_H
#define COMBAT_H

#define FIG_DATA        INHERIT_PATH"combat/combat_fighter_data"
#define PUT_CARD_D      INHERIT_PATH"combat/combat_d/put_card_d"
#define PER_CARD_D      INHERIT_PATH"combat/combat_d/perform_card_d"

 //战斗中身份类型
#define COM   0 
#define USER1 1
#define ENV   2
#define USER2 3

#define FIGHT_PVE 0
#define FIGHT_PVP 1

//战斗中发生的事件
#define None    0    //无动作
#define ENT     1    //获得 手牌/状态/物品
#define MYS     2    //非凡特性效果
#define PUT     3    //使用 手牌/物品等
#define ACT     4    //直接动作
#define ENT_R   5    //失去手牌/状态/物品
#define MYS_R   6    //失去非凡特性效果
#define SUM     7    //获得召唤物
#define SUM_R   8    //失去召唤物

#define F_INFO class f_info
//定义结构体 f_info，用于记录每一条战斗记录
class f_info {
    string str;   //行为的描述
    object ob1;   //该行为发出对象,可以为0
    int act;       //行为类型
    object status; //发出的行为对象
    object ob2;   //该行为目标对象,可以为0
}

#endif // COMBAT_H
