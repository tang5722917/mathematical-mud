/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-06 16:36:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-18 20:04:25
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
