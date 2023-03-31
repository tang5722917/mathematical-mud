/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-31 18:37:26
 * @FilePath: \mysticism-mud\inherit\combat\combat_single.c
 * @Description:  单人战斗基类
 *                提供单人战斗的UI
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <ansi.h>
#include <mxp.h>

#define USER 0
#define ENV 1

inherit INHERIT_PATH "combat/combat_UI";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env;

void print_fight_UI(string msg)
{
    MXP_message("FIG",msg,ob1);
}

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
//定义玩家的初始行为
string * fight_init_user(object user){return 0;}
//定义电脑地初始行为
string * fight_init_env(object env){return 0;}
//定义玩家的战斗结束时行为
string * fight_end_user(object user){return 0;}
//定义电脑的战斗结束时行为
string * fight_end_env(object env){return 0;}
object get_player1()
{
    return ob1;
}

//结束战斗
int fight_end(object ob)
{
    string * str;
    str = fight_end_user(ob1);
    {
        str = print_color_fig(str,USER);
        fight_info += str;
    }    
    str = fight_end_env(ob2);
    if (str != 0){
        str = print_color_fig(str,ENV);
        fight_info += str;
    }
    foreach(string s in fight_info)
        write(s);
    return 1;
}

int fight_init()
{
    string * str;
    str = ({"你的对手为："+ ob2->short()});
    fight_info += str;
    str = fight_init_user(ob1);
    if (str != 0)
    {
        str = print_color_fig(str,USER);
        fight_info += str;
    }
    str = fight_init_env(ob2);
    if (str != 0){
        str = print_color_fig(str,ENV);
        fight_info += str;
    }
    fight_info += ({"新的回合开始"});
    return sizeof(fight_info);
}

//定义战斗是否能退出， 默认不能退出
int is_quit_combat()
{
    return 0;
}


string fight_main_UI(int fight_time,int fight_round)
{
    string msg;
    msg ="<!ELEMENT UI FLAG='UI'><UI>";
    msg +="第" + fight_round + "回合   |地点："+fight_env->short()+"\n";
    msg += ob2_status(ob2);
    msg += ob2_equip(ob2);
    msg += ob2_cards(ob2);
    msg += out_area();
    msg += ob1_cards(ob1);
    msg += ob1_equip(ob1);
    msg += ob1_status(ob1);
    msg += "</UI>";
    return msg;
}
