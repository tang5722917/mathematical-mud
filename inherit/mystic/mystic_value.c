/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-20 18:10:25
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-21 01:30:34
 * @FilePath: \mysticism-mud\inherit\mystic\mystic_value.c
 * @Description: 处理非凡特性对数值的影响
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
//序列等级 0-9
protected int mystic_rank=9;
//定义非凡特性对数值的影响
//hp
int hp_val=0;
float hp_per=1.0;
//mp
int mp_val=0;
float mp_per=1.0;
//str
int str_val=0;
float str_per=1.0;
//agi
int agi_val=0;
float agi_per=1.0;
//sen
int sen_val=0;
float sen_per=1.0;
//int
int cra_val=0;
float cra_per=1.0;
//cra
int luk_val=0;
float luk_per=1.0;
//luk
int mys_val=0;
float mys_per=1.0;
//mys
int value_mys()
{
    return (10-mystic_rank) * 5;
}


vodi update_init_value(object living)
{
    living->query_sub_attr("max_hp",hp_per);
    living->query_add_attr("max_hp",hp_val);
    living->query_sub_attr("max_mp",hp_per);
    living->query_add_attr("max_mp",hp_val);
    living->query_sub_attr("max_int",hp_per);
    living->query_add_attr("max_int",hp_val);
    living->query_sub_attr("max_cra",hp_per);
    living->query_add_attr("max_cra",hp_val);

    living->query_sub_attr("str",hp_per);
    living->query_add_attr("str",hp_val);
    living->query_sub_attr("agi",hp_per);
    living->query_add_attr("agi",hp_val);
    living->query_sub_attr("sen",hp_per);
    living->query_add_attr("sen",hp_val);
    living->query_sub_attr("luk",hp_per);
    living->query_add_attr("luk",hp_val);

    living->set_attr("max_hp", base_hp);   // 当前HP
    living->set_attr("max_mp", base_mp);   // 当前MP
    living->set_attr("max_int", base_int); // 当前理智
    living->set_attr("max_cra", base_cra); // 当前疯狂

    living->query_add_attr("mys",value_mys());
}

