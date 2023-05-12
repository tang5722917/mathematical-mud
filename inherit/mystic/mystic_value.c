/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-20 18:10:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 17:03:17
 * @FilePath: \mysticism-mud\inherit\mystic\mystic_value.c
 * @Description: 处理非凡特性对数值的影响
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */

//定义非凡特性对数值的影响
//hp
int hp_val(){return 0;}
float hp_per(){return 1.0;}
//mp
int mp_val(){return 0;}
float mp_per(){return 1.0;}
//str
int str_val(){return 0;}
float str_per(){return 1.0;}
//agi
int agi_val(){return 0;}
float agi_per(){return 1.0;}
//sen
int sen_val(){return 0;}
float sen_per(){return 1.0;}
//int
int int_val(){return 0;}
float int_per(){return 1.0;}
//cra
int cra_val(){return 0;}
float cra_per(){return 1.0;}
//luk
int luk_val(){return 0;}
float luk_per(){return 1.0;}
//mys

//序列等级 0-9
int mystic_rank()
{
    return 9;
}
//返回非凡特性点数
int value_mys()
{
    return ((10-mystic_rank()) * 5);
}


void update_init_value(object living)
{
    living->query_rat_attr("max_hp",hp_per());
    living->query_add_attr("max_hp",hp_val());
    living->query_rat_attr("max_mp",mp_per());
    living->query_add_attr("max_mp",mp_val());
    living->query_rat_attr("max_int",int_per());
    living->query_add_attr("max_int",int_val());
    living->query_rat_attr("max_cra",cra_per());
    living->query_add_attr("max_cra",cra_val());

    living->query_rat_attr("str",str_per());
    living->query_add_attr("str",str_val());
    living->query_rat_attr("agi",agi_per());
    living->query_add_attr("agi",agi_val());
    living->query_rat_attr("sen",sen_per());
    living->query_add_attr("sen",sen_val());
    living->query_rat_attr("luk",luk_per());
    living->query_add_attr("luk",luk_val());

    living->set_attr("hp", living->query_attr("max_hp"));   // 当前HP
    living->set_attr("mp", living->query_attr("max_mp"));   // 当前MP
    living->set_attr("int", living->query_attr("max_int")); // 当前理智
    living->set_attr("cra", living->query_attr("max_cra")); // 当前疯狂

    living->query_add_attr("mys",value_mys());
}
