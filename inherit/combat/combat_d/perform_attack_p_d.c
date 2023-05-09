/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-09 02:46:03
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 08:23:39
 * @FilePath: /mysticism-mud/inherit/combat/combat_d/perform_attack_p_d.c
 * @Description: 处理物理攻击效果
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */

 string attack_p(object *user,object card_ob,object combat)
 {
     return card_ob->card_effect_descript();
 }
