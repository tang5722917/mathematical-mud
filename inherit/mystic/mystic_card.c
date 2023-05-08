/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:21:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 16:47:06
 * @FilePath: \mysticism-mud\inherit\mystic\mystic_card.c
 * @Description: 非凡特性产生的卡牌
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card_control.h>
nosave protected object card_ob;

varargs int mystic_card(string s_card, int weight, int luk)
{
    if(weight == 0)
        weight = 10;
    if(!objectp(card_ob))
        card_ob = new(INHERIT_PATH "entity/liv_card_data");
    card_ob->add_card(s_card,weight,luk);
    return card_ob->number_card();
}

object get_card_ob(){return card_ob;}
string get_card_list()
{
    CARD_ASSIGN *c;
    string s = "";
    object ob = get_card_ob();
    c = ob->get_card_q();
    foreach(CARD_ASSIGN card in c)
    {
        s +=card->card + card->weight + "\n";
    }
    return s;
}

int number_card(){return card_ob->number_card();}
