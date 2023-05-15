/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-04 16:53:41
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-13 18:30:14
 * @FilePath: /mysticism-mud/World/base/summon/01/paper_replace.c
 * @Description: 召唤物：替身纸人
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <summon.h>
//召唤物名称
string summon_name(){return "替身纸人";}
//召唤物short 介绍
string summon_explain(){return "血量为1的替身纸人，可以抵挡一次单体攻击";}
//3-summon 01-对应非凡途径序号1占卜家 7-魔术师 01编号
int summon_id(){return 301701;}
//替身纸人HP 1
int summon_hp(){return 1;}
//替身纸人类型为固定物理攻击
int summon_type(){return FIX_ATTACK_P;}
