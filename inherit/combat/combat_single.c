/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-05 14:44:17
 * @FilePath: \mysticism-mud\inherit\combat\combat_single.c
 * @Description: PVE 1v1 战斗基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <mxp.h>
#include <combat.h>

inherit INHERIT_PATH "combat/combat_UI_single";

void init(object o1,object o2,object env)
{
    ob1 = o1;
    ob2 = o2;
    fight_env = env;
    //战斗过程信息
    fight_info = ({});
    //公共物序列
    env_obj = ({});
    //召唤物物序列
    ob_summon1 = ({});
    ob_summon2 = ({});
    //建立战斗双方的数据类，并初始化
    ob1_data = ({});
    ob2_data = ({});
    err = new(_ERR);
    err->init(this_object());
    ob1_data += ({add_new_fighter(ob1)});
    ob2_data += ({add_new_fighter(ob2)});
}
//定义玩家的初始行为
int fight_init_user(object user){return 0;}
//定义电脑地初始行为
int fight_init_env(object env){return 0;}
//定义玩家的战斗结束时行为
int fight_end_user(object user){return 0;}
//定义电脑的战斗结束时行为
int fight_end_env(object env){return 0;}

object get_player1(){return ob1;}
object get_player2(){return ob2;}
//结束战斗
int fight_end()
{
    script->combat_event_end(this_object(),ob1,ob2);
    ob1->end_fight();
    fight_end_user(ob1);  
    fight_end_env(ob2);
    
    return length_fight_info();
}

int fight_init(object scr)
{
    script = scr;
    add_f_info("对手为："+ ob2->short(),ob1);
    fight_init_user(ob1);
    fight_init_env(ob2);
    script->combat_event_init(this_object(),ob1,ob2);
    add_f_info("本回合结束");
    return length_fight_info();
}

//定义战斗是否能退出， 默认不能退出
int is_quit_combat()
{
    return 0;
}


string fight_main_UI(int fight_time,int fight_round)
{
    string msg="";
    if( MXP_USER(ob1) )
        msg +="<!ELEMENT UI FLAG='UI'>\n<UI>";
    msg +="第" + fight_round + "回合   |地点："+fight_env->short()+"\n";
    msg += ob2_s_status();
    msg += ob2_s_status_data();
    msg += ob2_s_equip();
    msg += ob2_s_cards();
    msg += out_s_area();
    msg += ob1_s_cards();
    msg += ob1_s_equip();
    msg += ob1_s_status_data();
    msg += ob1_s_status();
    if(MXP_USER(ob1))
        msg += "</UI>";
    return msg;
}
void print_fight_UI(string msg)
{
    MXP_message("FIG",msg,ob1);
}

void next_round(int fight_round)
{
    message("FIG","第"+fight_round+"回合出牌开始",ob1);
}

void msg_end(){
    message("FIG",BGRN "战斗结束了!" NOR,ob1);}
