/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-26 17:55:39
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 19:02:28
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\put_card_d.c
 * @Description: 处理出牌操作
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


int perform(object combat,object *put_ob_card,object user)
{
    foreach(object ob in put_ob_card)
        combat->put_f_ent(file_name(ob),user);
}

//不出牌，跳过本回合
void put_card_d_pass(object combat)
{
    combat->add_f_info("本回合结束");
}

int put_card(object combat,int *n_card,object user)
{
    object o_data,*ob_card,*put_ob_card=({});
    object card_ob;
    o_data = combat->get_ob1_data();
    ob_card = o_data->get_card();
    foreach(int i in n_card)
    {
        card_ob = ob_card[i];
        put_ob_card += ({card_ob});
    }
    perform(combat,put_ob_card,user);
    combat->add_f_info("本回合结束");
    o_data->remove_card(put_ob_card);
    return 0;
}
