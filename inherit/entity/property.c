/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-06 16:36:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-03 18:07:17
 * @FilePath: \mysticism-mud\inherit\entity\property.c
 * @Description: 玩家持有的带属性的物品基类
 *              
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
 inherit INHERIT_PATH "entity/entity";
 inherit _NAME;
 inherit _DBASE;
 inherit _MOVE;
 inherit _CLEAN_UP;
 
#include <ansi.h>


//特殊物品名称
string property_name(){return "特殊物品";}
//装备short 介绍
string property_explain(){return "可以储存其他物品的特殊物品";}
//装备id
int property_id(){return 90;}

int entity_id(){return property_id();}
string mxp_name(){return property_name();}
string mxp_explain(){return property_explain();}
string print_mxp_other(object user){return print_mxp_name(10,user);}

int is_move()
{
    return query("property_move") ;
}

int is_get()
{
    return  query("property_get";
}

int is_visible()
{
    return  query("property_visible";
}

void set_property_init(int move,int get,int visible,string* id,string name)
{
    set("property_move", move);
    set("property_get",get);
    set("property_visible",visible);
    set_name(YEL+name+NOR,id);
}

//look 接口函数，处理被look事件
void look(object me,object env){}

// search接口函数，处理search事件
void search(object me,object env){write("没有什么特别的发现。\n ");}

//ask 接口函数，处理被ask事件
void answer(object me,object env){write("这个东西明显没有办法回答你的问题\n");}

string honor_name(object me, object ob)
{
    return "这个奇怪的东西";
}
