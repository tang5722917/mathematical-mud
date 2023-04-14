/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-14 18:35:48
 * @FilePath: \mysticism-mud\inherit\combat\combat_data.c
 * @Description: 战斗数据基础类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 
#include <combat.h> 
inherit CORE_CLEAN_UP;

//战斗过程信息
protected mixed *fight_info;

//ob1 手牌序列， PVE中的玩家
protected object *ob1_card;
//ob2 手牌序列， PVE中的电脑
protected object *ob2_card;
//ob1 状态序列， PVE中的玩家
protected object *ob1_status;
//ob2 状态序列， PVE中的电脑
protected object *ob2_status;
//ob1 装备序列， PVE中的玩家
protected object *ob1_equip;
//ob2 装备序列， PVE中的电脑
protected object *ob2_equip;
//ob1 召唤物序列， PVE中的玩家
protected object *ob1_summon;
//ob2 召唤物序列， PVE中的电脑
protected object *ob2_summon;
//公共物序列
protected object *env_obj;


string add_card(object *ob, object o)
{
    ob += ({o});
    return "获得能力牌："+ o->card_name();
}

varargs void add_f_info(string str, object ob1,object ob2)
{
    F_INFO f;
    f = new(F_INFO,str:str,ob1:ob1,ob2:ob2);
    fight_info +=({f});
}

int length_fight_info(){return sizeof(fight_info);}
