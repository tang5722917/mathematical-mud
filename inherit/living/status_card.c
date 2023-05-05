/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 15:32:24
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-05 16:03:51
 * @FilePath: \mysticism-mud\inherit\living\status_card.c
 * @Description: living Card管理基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

protected object *add_card_ob;
protected mapping *card_q;

void update_card_q()
{
    mixed temp;
    foreach(object ob in add_card_ob)
    {
        temp = ob->add_card_q();
    }
}
