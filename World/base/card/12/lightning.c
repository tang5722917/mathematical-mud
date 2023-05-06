/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-06 19:09:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-06 19:19:29
 * @FilePath: \mysticism-mud\World\base\card\12\lightning.c
 * @Description: 闪电攻击Card
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card.h>

 string card_name(){return "火球术";}
 string card_short(){return "发出一个火球攻击敌人，火球的威力取决于灵性";}
 //1-card 12-对应非凡途径序号12猎人 7-纵火家 01编号
 int card_id(){return 112701;}
 
 //卡片类型： 单体物理攻击
 int *perform_type(){return ({CATTACK1});}

 