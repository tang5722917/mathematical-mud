/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 15:32:24
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 17:28:50
 * @FilePath: \mysticism-mud\inherit\living\status_card.c
 * @Description: living Card管理基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <card_control.h>

protected object *card_ob;
nosave protected mapping card_q;

object * get_card_ob(){return card_ob;}
mapping get_card_q(){return card_q;}

string get_one_card()
{
    string card;
    if( (mapp(card_q)) && (sizeof(card_q) > 0))
    {
        card = element_of_weighted(card_q);
        map_delete(card_q,card);
        return card;
    }
    else return 0;
}

int number_card_ob(){return sizeof(card_ob);}
int number_card_q(){return sizeof(card_q);}

void clear_card_ob(){card_ob = ({});}
void add_card_q(CARD_ASSIGN c)
{
    if(!mapp(card_q))
        card_q = ([]);
    card_q[c->card] = c->weight;
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
    }
}

string get_card_list()
{
    string s="";
    s += "玩家Card 组数:"+ number_card_ob()+"\n";
    s += "玩家Card 数:"+ number_card_q()+"\n";
    if(mapp(card_q))
        foreach (string str,int w in card_q)
            s += "card_name:"+str+" 权重："+w+"\n";
    return s;
}

void add_card_ob(object ob)
{
    if(!card_ob)
        card_ob = ({});
    card_ob += ({ob});
}
