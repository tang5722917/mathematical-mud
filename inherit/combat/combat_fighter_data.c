/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-14 19:56:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-21 20:34:40
 * @FilePath: \mysticism-mud\inherit\combat\combat_fighter_data.c
 * @Description: 战斗living数据
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <combat.h> 
inherit _CLEAN_UP;

//手牌序列
nosave protected object *ob_card;
//状态序列
nosave protected object *ob_status;
//装备序列
nosave protected object *ob_equip;
//召唤物序列
nosave protected object *ob_summon;

nosave protected string name;
void init()
{
    ob_card=({});
    ob_status=({});
    ob_equip=({});
    ob_summon=({});
}

void create(string ob_name)
{
    name = ob_name;
    init();
}

object *get_card(){return ob_card;}
object *get_status(){return ob_status;}
object *get_equip(){return ob_equip;}
object *get_summon(){return ob_summon;}

void add_entity(object o)
{
    if( inherits(CORE_STD_CARD,o)  )
        ob_card += ({o});
    else if( inherits(CORE_STD_EQUIP,o)  )
        ob_equip += ({o});
    else if( inherits(CORE_STD_SUMMON,o)  )
        ob_summon += ({o});
    else if( inherits(CORE_STD_STATUS,o)  )
        ob_status += ({o});
}

void remove_entity(object o)
{
    if( inherits(CORE_STD_CARD,o)  )
        ob_card -= ({o});
    else if( inherits(CORE_STD_EQUIP,o)  )
        ob_equip -= ({o});
    else if( inherits(CORE_STD_SUMMON,o)  )
        ob_summon -= ({o});
    else if( inherits(CORE_STD_STATUS,o)  )
        ob_status -= ({o});
}
