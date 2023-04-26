/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-26 17:55:39
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-26 19:35:41
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\put_card_d.c
 * @Description: 处理出牌操作
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

int put_card(object combat,int *n_card)
{
    object o_data,*ob_card;
    o_data = combat->get_ob1_data();
    ob_card = o_data->get_card();
    write(sizeof(ob_card)+"\n");
}
