/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-04 17:43:41
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-13 19:12:24
 * @FilePath: /mysticism-mud/inherit/combat/combat_d/summon_add_d.c
 * @Description: 新增/初始化召唤物
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <summon.h>

string summon_place(int n)
{
    if( n < 10 )
        return "我方召唤区"
}

string add_summon(object *user,object card_ob,object combat)
{
    string str="";
    object *su,su_data;
    su = card_ob->perform_summon();
    s += WHT+"使用"+card_ob->card_name()+"牌召唤出"+sizeof(su)+"个召唤物"+ NOR "\n";
    foreach(object o in su){
        s += WHT +"召唤出"+o->summon_name()"置于"+summon_place()+NOR "\n";
        su_data = o->init_summon_data();
        
    }
    return str;
}
