/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:08:22
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 15:59:35
 * @FilePath: \mysticism-mud\World\base\card\01\air_attack.c
 * @Description:  空气炮
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <card.h>

string card_name(){return "空气子弹";}
string card_short(){return "通过空气子弹来攻击敌人，子弹的威力取决于灵性";}
//1-card 01-对应非凡途径序号1占卜家 4-魔术师 02编号
int card_id(){return 101702;}
string card_effect_descript(){return "发出空气子弹攻击";}
//卡片类型： 单体物理攻击
int *perform_type(){return ({CATTACK1});}

//攻击参数设置  基础攻击参数1.0, 表示每次基础伤害为灵性1.0倍
//属性： 风 基础命中：100   单体攻击
//攻击消耗mp 10
mapping  perform_attack1(){
    return attack_type1(1.0,0,100,A_WIND,1,10);}
