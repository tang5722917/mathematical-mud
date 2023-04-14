/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-14 19:56:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-14 20:08:07
 * @FilePath: \mysticism-mud\inherit\combat\combat_fighter_data.c
 * @Description: 战斗living数据
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <combat.h> 
inherit CORE_CLEAN_UP;

//手牌序列
nosave protected object *ob_card;
//状态序列
nosave protected object *ob_status;
//装备序列
nosave protected object *ob_equip;
//召唤物序列
nosave protected object *ob_summon;


void init()
{
    ob_card=({});
    ob_status=({});
    ob_equip=({});
    ob_summon=({});
}

object *get_card(){return ob_card;}
object *get_status(){return ob_status;}
object *get_equip(){return ob_equip;}
object *get_summon(){return ob_summon;}
