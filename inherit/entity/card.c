/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-27 15:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-19 17:58:18
 * @FilePath: \mysticism-mud\inherit\entity\card.c
 * @Description: 卡牌实现基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";

#include <ansi.h>


//卡牌名称
string card_name(){return "";}
//卡牌short 介绍
string card_short(){return "";}
//卡牌id
int card_id(){return 10;}

int entity_id(){return card_id();}
string mxp_name(){return card_name();}
string mxp_explain(){return card_short();}
