/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-12 16:31:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 16:59:03
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_hit_d.c
 * @Description: 处理攻击是否命中
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <attack.h>
#include <combat.h>

int perform_attack_hit(object user , object target,ATTACK_P p,object card_ob)
{
    int hit_rate;
    hit_rate = random(100);
    if(hit_rate < p->hit )
        return 1;
    else return 0;
}
