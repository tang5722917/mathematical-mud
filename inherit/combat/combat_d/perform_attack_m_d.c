/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-09 10:15:01
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 10:18:09
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_attack_m_d.c
 * @Description: 处理非凡攻击效果
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <attack.h>
#include <combat.h>

 string attack_m(object *user,object card_ob,object combat)
 {
     return card_ob->card_effect_descript();
 }
