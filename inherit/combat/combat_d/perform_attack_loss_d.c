/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-12 15:10:04
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 16:30:10
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_attack_loss_d.c
 * @Description: 处理使用技能的消耗
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <attack.h>

string attack_loss(object user, A_VALUE a,object card_ob)
 {
     string str = "";
     if(a->hp > 0){
         str += YEL +"使用"+card_ob->card_name()+"消耗HP值:"+a->hp+ NOR +"\n";
         user -> query_sub_attr("hp",a->hp);
     }
     if(a->mp > 0){
         str += YEL +"使用"+card_ob->card_name()+ "消耗MP值:"+a->mp+ NOR +"\n";
         user -> query_sub_attr("mp",a->mp);
     }
     if(a->str > 0){
         str += YEL +"使用"+card_ob->card_name()+ "力量下降:"+a->str+ NOR +"\n";
         user -> query_sub_attr("str",a->str);
     }
     if(a->agi > 0){
         str += YEL +"使用"+card_ob->card_name()+ "敏捷下降:"+a->agi+ NOR +"\n";
         user -> query_sub_attr("agi",a->agi);
     }
     if(a->sen > 0){
         str += YEL +"使用"+card_ob->card_name()+ "灵性下降:"+a->sen+ NOR +"\n";
         user -> query_sub_attr("sen",a->sen);
     }
     if(a->intt > 0){
         str += YEL +"使用"+card_ob->card_name()+ "疯狂上升:"+a->intt+ NOR +"\n";
         user -> query_sub_attr("int",a->intt);
     }
     if(a->cra > 0){
         str += YEL +"使用"+card_ob->card_name()+ "幸运下降:"+a->cra+ NOR +"\n";
         user -> query_sub_attr("cra",a->cra);
     }
     if(a->luk > 0){
         str += YEL + "使用"+card_ob->card_name()+"消耗MP值:"+a->luk+ NOR +"\n";
         user -> query_sub_attr("luk",a->luk);
     }
     return str;
 }
