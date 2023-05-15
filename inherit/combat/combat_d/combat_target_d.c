/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-15 17:12:15
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-15 17:34:07
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\combat_target_d.c
 * @Description: 决定攻击目标
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <combat.h>
 //获得对方object  type 1 为Card目标为对方， 0 Card目标为自身
object * get_attack_target(object user,object combat,int type )
{
    if(inherits(CORE_STD_FIGHT_S, combat)) // 1v1 pve
    {
        if(type)
        {
            if(user == combat->get_player1())
            {
                if(combat->length_ob_summon2())
                    return ({combat->get_ob1_data(),combat->get_summon_data(2)});
                else
                    return ({combat->get_ob1_data(),combat->get_ob2_data()});
            }
            else {
                if(combat->length_ob_summon1())
                    return ({combat->get_ob2_data(),combat->get_summon_data(1)});
                else
                    return ({combat->get_ob2_data(),combat->get_ob1_data()});
            }
        }
        else return ({user});
    }
}
