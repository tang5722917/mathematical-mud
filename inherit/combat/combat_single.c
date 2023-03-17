/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-17 14:47:32
 * @FilePath: \mysticism-mud\inherit\combat\combat_single.c
 * @Description:  单人战斗基类
 *                提供单人战斗的UI
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <ansi.h>

#define USER 0
#define ENV 1

inherit INHERIT_PATH "combat/combat_UI";
inherit INHERIT_PATH "combat/combat_base";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env;

void print_fight(string msg)
{
    message("FIG",msg,ob1);
}


void create(object o1,object o2,object env)
{
    ob1 = o1;
    ob2 = o2;
    fight_env = env;
}

string * fight_init_user(){return 0;}
string * fight_init_env(){return 0;}
object get_player1()
{
    return ob1;
}

int fight_init()
{
    string * str;
    str = ({"你的对手为："+ ob2->short()});
    fight_info += str;
    str = fight_init_user();
    if (str != 0)
    {
        str = print_color_fig(str,USER);
        fight_info += str;
    }
    str = fight_init_env();
    if (str != 0){
        str = print_color_fig(str,ENV);
        fight_info += str;
    }
    fight_info += ({"新的回合开始"});
    return sizeof(fight_info);
}



string fight_main_UI(int fight_time,int fight_round)
{
    string msg;
    msg = "第" + fight_round + "回合   |地点："+fight_env->short()+"\n";
    msg += ob2_status(ob2);
    msg += ob2_equip(ob2);
    msg += ob2_cards(ob2);
    msg += out_area();
    msg += ob1_cards(ob1);
    msg += ob1_equip(ob1);
    msg += ob1_status(ob1);
    return msg;
}





