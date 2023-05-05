/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 16:05:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-05 16:14:03
 * @FilePath: \mysticism-mud\inherit\entity\liv_card_data.c
 * @Description: 用于记录装备/非凡特性/召唤物对手牌的影响
 *               与living/status_card类配合
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected mixed * card_q,

mixed * add_card_q(){return card_q;}

void add_card(string card,int weight)  //weight 0 ~ 100
{
    mixed * card = ({card,weight});
    if(card_q == 0)
        card_q = ({});
    card_q += ({card});
}
