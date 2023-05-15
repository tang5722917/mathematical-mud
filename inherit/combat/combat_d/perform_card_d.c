/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:11:04
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-15 19:40:38
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_card_d.c
 * @Description: 处理Card执行效果
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <combat.h>

int perform(object user,object card_ob,object combat)
{
    //获得Card效果类型
    int *perform_q = card_ob->perform_type();
    string card_effect;
    object target_ob = load_object(INHERIT_PATH "combat/combat_d/combat_target_d");
    foreach(int i in perform_q){
        switch(i%8)
        {
            case 0:
                break;     //特殊技能  eg:占卜/盗窃等
            case 1:        //己方BUFF
                break;
            case 2:       //敌方BUFF
                break;
            case 3:       //召唤
                card_effect = load_object(SUMMON_ADD_D)->add_summon(user,card_ob,combat);
                break;
            case 4:       //物理攻击
                card_effect = load_object(ATTACK_P_D)->attack_p(target_ob->get_attack_target(user,combat,1),card_ob,combat);
                break;
            case 5:       //非凡攻击
                break;
            case 6:       //己方属性
                break;
            case 7:       //敌方属性
                break;
            default:break;
        }
    }
    combat->print_info(card_effect);
    return 1;
}
