/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 15:32:24
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-06 21:25:40
 * @FilePath: /mysticism-mud/inherit/living/status_card.c
 * @Description: living Card管理基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card_control>

protected object *card_ob;
nosave protected mapping card_q;

object get_one_card()
{
    object card;
    card = element_of_weighted(card_q);
    map_delte(card_q,card);
    return card;
}

void add_card_q(CARD_ASSIGN c)
{
    card_q[c->card] = c->weight;
}

void update_card_q()
{
    CARD_ASSIGN *temp;
    foreach(object ob in add_card_ob)
    {
        temp = ob->get_card_q();
        foreach(CARD_ASSIGN c in temp)
            add_card_q(c);
    }
}

void add_card_ob(object ob)
{
    if(!card_ob)
        card_ob = ({});
    card_ob += ({ob});
}
