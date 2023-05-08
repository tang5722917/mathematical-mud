/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 16:05:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 11:49:50
 * @FilePath: \mysticism-mud\inherit\entity\liv_card_data.c
 * @Description: 用于记录装备/非凡特性/召唤物对手牌的影响
 *               与living/status_card类配合
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card_control.h>

nosave protected CARD_ASSIGN * card_q;

void add_card(string s_card,int weight,int luk)  //weight >0 default 10
{
    object card;
    CARD_ASSIGN c;
    card = load_object(s_card);
    c = new(CARD_ASSIGN,card:card,weight:weight,luk:luk);
    if(card_q == 0)
        card_q = ({});
    card_q += ({c});
}

CARD_ASSIGN * get_card_q(){ return card_q; }

int number_card(){return sizeof(card_q);}
