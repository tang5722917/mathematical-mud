/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-14 19:56:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 18:47:34
 * @FilePath: \mysticism-mud\inherit\combat\combat_fighter_data.c
 * @Description: 战斗living数据
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <combat.h> 
inherit INHERIT_PATH "living/status_value" ;
inherit INHERIT_PATH "living/status_mystic" ;
inherit INHERIT_PATH "living/status_affect" ;
inherit INHERIT_PATH "living/status_card" ;
inherit _CLEAN_UP;

//手牌序列
nosave protected object *ob_card;
//状态序列
nosave protected object *ob_status;
//装备序列
nosave protected object *ob_equip;
//所属的user
nosave protected object user_ob;
//是否完成出牌
nosave protected int end_round;
//将living 类中的战斗相关数据copy到战斗fighter_data中
//战斗全程只对fighter_data进行修改
void init(object ob)
{
    ob_card=({});
    ob_status=({});
    ob_equip=({});
    user_ob = ob;
    living_value = copy(ob->get_living_value());
    living_mystic = copy(ob->get_living_mystic());
    living_mystic_id = copy(ob->get_living_mystic_id());
    card_ob = copy(ob->get_card_ob());
    card_q = copy(ob->get_card_q());
    end_round = 0;
}

void end_round(){end_round = 1;}
void start_round(){end_round = 0;}
int get_put_round(){return end_round;}

int get_num_card(){return sizeof(ob_card);}

object *get_card(){return ob_card;}
object *get_status(){return ob_status;}
object *get_equi(){return ob_equip;}

void remove_card(object *obs){ob_card -= obs;}
void remove_status(object *obs){ob_status -= obs;}
void remove_equi(object *obs){ob_equip -= obs;}

void add_entity(object o)
{
    if( inherits(CORE_STD_CARD,o)  )
        ob_card += ({o});
    else if( inherits(CORE_STD_EQUIP,o)  )
        ob_equip += ({o});
    else if( inherits(CORE_STD_STATUS,o)  )
        ob_status += ({o});
}

void remove_entity(object o)
{
    if( inherits(CORE_STD_CARD,o)  )
        ob_card -= ({o});
    else if( inherits(CORE_STD_EQUIP,o)  )
        ob_equip -= ({o});
    else if( inherits(CORE_STD_STATUS,o)  )
        ob_status -= ({o});
}
