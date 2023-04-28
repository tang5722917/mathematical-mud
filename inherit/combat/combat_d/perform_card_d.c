/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:11:04
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 19:20:19
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_card_d.c
 * @Description: 处理Card执行效果
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


int perform(object user,object card_ob,object combat)
{
    object *target_user;    //Card 潜在的玩家目标
    object *target_summon;  //Card 潜在的召唤物目标
    int *perform_q = card_ob->perform_type();
    foreach(int i in perform_q){
        switch(i)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:break;
        }
    }
    return 1;
}
