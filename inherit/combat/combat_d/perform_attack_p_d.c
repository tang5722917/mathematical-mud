/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-09 02:46:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-11 20:44:56
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_attack_p_d.c
 * @Description: 处理物理攻击效果
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <attack.h>

string attack_loss(object user, A_VALUE a)
{
    return "消耗MP值"+a->mp;
}

string attack_effect(object target,ATTACK_P p )
{
    return "";
}

 string attack_p(object *user,object card_ob,object combat)
 {
    string str = "";
    mapping card_m = card_ob->perform_attack1();
    if(sizeof(user) == 2)
    {
        str += card_ob->card_effect_descript();
        str += attack_loss(user[0],card_m["attack_loss"] );
        str += attack_effect(user[1], card_m["attack_base"] );
    }
    else{}
    return str;
 }
