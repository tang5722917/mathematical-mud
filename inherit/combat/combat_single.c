/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-13 18:34:37
 * @FilePath: \mysticism-mud\inherit\combat\combat_single.c
 * @Description:  单人战斗基类
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <ansi.h>
#include <mxp.h>
#include <combat.h>

inherit INHERIT_PATH "combat/combat_UI_single";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env,script;

void create(object o1,object o2,object env)
{
    ob1 = o1;
    ob2 = o2;
    fight_env = env;
    //战斗过程信息
    fight_info = ({});
    //ob1 手牌序列， PVE中的玩家
    ob1_card = ({});
    //ob2 手牌序列， PVE中的电脑
    ob2_card = ({});
    //ob1 状态序列， PVE中的玩家
    ob1_status = ({});
    //ob2 状态序列， PVE中的电脑
    ob2_status = ({});
    //ob1 装备序列， PVE中的玩家
    ob1_equip = ({});
    //ob2 装备序列， PVE中的电脑
    ob2_equip = ({});
    //ob1 召唤物序列， PVE中的玩家
    ob1_summon = ({});
    //ob2 召唤物序列， PVE中的电脑
    ob2_summon = ({});
    //公共物序列
    env_obj = ({});    
}
//定义玩家的初始行为
mixed * fight_init_user(object user){return 0;}
//定义电脑地初始行为
mixed * fight_init_env(object env){return 0;}
//定义玩家的战斗结束时行为
mixed * fight_end_user(object user){return 0;}
//定义电脑的战斗结束时行为
mixed * fight_end_env(object env){return 0;}

object get_player1(){return ob1;}
object get_player2(){return ob2;}
//结束战斗
int fight_end()
{
    mixed * str;
    script->combat_event_end(ob1,ob2);
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
    return sizeof(fight_info);
}

int fight_init(object scr)
{
    mixed * str;
    script = scr;
    str = ({"对手为："+ ob2->short(),ob1});
    fight_info += ({str});
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
    script->combat_event_init(ob1,ob2);
    fight_info += ({({"本回合结束",0})});
    return sizeof(fight_info);
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
    msg += ob2_status(ob2);
    msg += ob2_equip(ob2);
    msg += ob2_cards(ob2);
    msg += out_area();
    msg += ob1_cards(ob1);
    msg += ob1_equip(ob1);
    msg += ob1_status(ob1);
    if(MXP_USER(ob1))
        msg += "</UI>";
    return msg;
}
void print_fight_UI(string msg)
{
    MXP_message("FIG",msg,ob1);
}

void print_fight(string msg)
{
    message("FIG",msg,ob1);
}

void next_round(int fight_round)
{
    message("FIG","第"+fight_round+"回合出牌开始",ob1);
}
