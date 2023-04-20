/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-27 15:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-20 20:14:50
 * @FilePath: \mysticism-mud\inherit\entity\equip.c
 * @Description: 卡牌实现基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";

#include <ansi.h>


//装备名称
string equip_name(){return "装备";}
//装备short 介绍
string equip_explain(){return "佩戴在持有者身上，为持有者提供各种能力";}
//装备id
int equip_id(){return 20;}
string print_equip_name(){return print_mxp_name(5);}
int entity_id(){return equip_id();}
string mxp_name(){return equip_name();}
string mxp_explain(){return equip_explain();}
