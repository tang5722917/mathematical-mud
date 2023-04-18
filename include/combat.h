/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 14:18:47
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-04-18 04:00:11
 * @FilePath: \mysticism-mud\include\combat.h
 * @Description: 战斗相关头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#ifndef COMBAT_H
#define COMBAT_H

#define FIG_DATA INHERIT_PATH"combat/combat_fighter_data"

 //战斗中身份类型
#define COM   0 
#define USER  1
#define ENV   2

#define FIGHT_PVE 0
#define FIGHT_PVP 1

#define F_INFO class f_info
//定义结构体 f_info，用于记录每一条战斗记录
class f_info {
    object ob1;   //该行为发出对象,可以为0
    object status; //发出的行为对象
    int act;       //行为类型
    object ob2;   //该行为目标对象,可以为0
    string str;   //行为的描述
}


#endif // COMBAT_H
