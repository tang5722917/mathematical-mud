/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-16 22:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 17:03:27
 * @FilePath: \mysticism-mud\inherit\combat\combat_UI_single.c
 * @Description: 提供单人战斗的UI
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#include <ansi.h>
#include  <combat.h>
inherit INHERIT_PATH "combat/combat_UI";

nosave protected object ob1;
nosave protected object ob2;
nosave protected object fight_env,script;

//战斗过程颜色控制
string print_color_fig(F_INFO str,int type)
{
    string s=str->str;
    if(str == 0)
        return 0;
    if((str->act == ENT)||(str->act == ENT_R)||(str->act == PUT))
        s += str->status->print_name(ob1);
    if(type == USER1 )
    {
        s = GRN + "你："+ s + NOR;
        return s;
    }
    if(type == ENV )
    {
        s = RED +str->ob1->id_list()[0] +"："+ s + NOR;
        return s;
    }
    if(type == COM )
    {
        s = BYEL + s + NOR;
        return s;
    }
    return 0;
}

//执行一条战斗指令的动作
void print_fight(F_INFO msg)
{
    int type;
    if(msg->ob1 == 0)
        type = COM;
    else if(msg->ob1 == ob1)
        type = USER1;
    else if(msg->ob1 == ob2)
        type = ENV;
    message("FIG",print_color_fig(msg,type),ob1);
    if(msg->act)
        perform(msg);
}

object get_ob1_data(){return ob1_data[0];}
object get_ob2_data(){return ob2_data[0];}
object get_ob_data(object ob)
{
    if(ob == ob1)
        return ob1_data[0];
    else
        return ob2_data[0];
}
string ob2_s_status(){return ::ob2_status(ob2_data[0]->get_status());}
string ob2_s_equip(){return ::ob2_equip(ob2_data[0]->get_equip());}
string ob2_s_cards(){return ::ob2_cards(ob2_data[0]->get_card());}
string out_s_area(){return ::out_area(ob1_data[0]->summon(),ob2_data[0]->summon());}
string ob1_s_cards(){return ::ob1_cards(ob1_data[0]->get_card());}
string ob1_s_equip(){return ::ob1_equip(ob1_data[0]->get_equip());}
string ob1_s_status(){return ::ob1_status(ob1_data[0]->get_status());}
string ob1_s_status_data(){
    string msg;
    msg = sprintf("  |%-22s%-14s%-14s%-11s| \n", ob1->short(),"血气"+ob1_data[0]->query_attr("hp")+"/"+ob1_data[0]->query_attr("max_hp")
    ,"精力"+ob1_data[0]->query_attr("mp")+"/"+ob1_data[0]->query_attr("max_mp"),"疯狂:"+ob1_data[0]->query_attr("cra"));
    return msg;
}

string ob2_s_status_data(){
    string msg="";
    msg = sprintf("  |%-22s%-14s%-14s%-11s| \n", ob2->short(),"血气"+ob2_data[0]->query_attr("hp")+"/"+ob2_data[0]->query_attr("max_hp")
    ,"精力"+ob2_data[0]->query_attr("mp")+"/"+ob2_data[0]->query_attr("max_mp"),"疯狂:"+ob2_data[0]->query_attr("cra"));
    return msg;
}

string print_ob1_ent(object *obs,int type)
{
    return print_line(obs,ob1,type);
}

string print_ob2_ent(object *obs,int type)
{
    if(wizardp(ob1))
        return print_line(obs,ob1,type);
    else
        return "";
}

//获取user手牌数量
int get_card_num(object user)
{
    return ob1_data[0]->get_num_card();
}
