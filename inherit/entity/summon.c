/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-04 18:41:38
 * @FilePath: \mysticism-mud\inherit\entity\summon.c
 * @Description: 召唤物基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <attack.h>
inherit INHERIT_PATH "entity/entity";

//召唤物名称
string summon_name(){return "召唤物";}
//召唤物short 介绍
string summon_explain(){return "出现于战场之上，协助主人战胜对手";}
//召唤物id
int summon_id(){return 10;}
string print_summon_name(object user){return print_mxp_name(6,user);}
int entity_id(){return summon_id();}
string mxp_name(){return summon_name();}
string mxp_explain(){return summon_explain();}
string summon_description(){return "召唤物的详细介绍";}
string entity_description(){return summon_description();}

int summon_hp(){return 0;}
int summon_mp(){return 0;}
int summon_str(){return 0;}
int summon_agi(){return 0;}
int summon_sen(){return 0;}
int summon_int(){return 0;}
int summon_cra(){return 0;}
int summon_luk(){return 0;}
int summon_mys(){return 0;}
int summon_type(){return 0;}
ATTACK_P summon_attack_p(){
    ATTACK_P p = get_attack_p(0,0,0,0,0);
    return p;
}
A_VALUE summon_attack_value(){
    return get_living_value(summon_hp(),summon_mp(),summon_str(),summon_agi()
        ,summon_sen(),summon_int(),summon_cra(),summon_luk(),summon_mys());
}
mapping summon_status(){
    mapping m=([]);
    m["value"] = summon_attack_value();
    m["attack_p"] = summon_attack_p();
    return m;
}
object init_summon_data()
{
    object data = new(INHERIT_PATH "entity/summon_data",this_object());
    data->init(summon_type(),summon_status());
}
