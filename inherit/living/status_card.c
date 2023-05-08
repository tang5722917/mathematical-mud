/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 15:32:24
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 15:25:21
 * @FilePath: \mysticism-mud\inherit\living\status_card.c
 * @Description: living Card管理基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card_control.h>

protected object *card_ob;
nosave protected mapping card_q;

object get_one_card()
{
    object card;
    card = element_of_weighted(card_q);
    map_delete(card_q,card);
    return card;
}

void add_card_q(CARD_ASSIGN c)
{
    card_q[c->card] = c->weight;
}

string get_card_list()
{
    string s="";
    foreach (string str,int w in card_q)
       s += "card_name:"+str+" 权重："+w+"\n";
    return s;
}

void update_card_q()
{
    CARD_ASSIGN *temp;
    if(card_ob){
        foreach(object ob in card_ob)
        {
            temp = ob->get_card_q();
            foreach(CARD_ASSIGN c in temp)
                add_card_q(c);
        }
        get_card_list();
    }
}

void add_card_ob(object ob)
{
    if(!card_ob)
        card_ob = ({});
    card_ob += ({ob});
}

void clear_card_ob(){card_ob = ({});}
