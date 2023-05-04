/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:11:04
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-04 17:11:56
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_card_d.c
 * @Description: 处理Card执行效果
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

//获得对方object


int perform(object user,object card_ob,object combat)
{
    //获得Card效果类型
    int *perform_q = card_ob->perform_type();
    object *target_ob;
    foreach(int i in perform_q){
        switch(i%7)
        {
            case 1:        //己方BUFF
                break;
            case 2:       //敌方BUFF
                break;
            case 3:       //召唤
                
                break;
            case 4:       //物理攻击

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
    return 1;
}
