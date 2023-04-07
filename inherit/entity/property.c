/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-06 16:36:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-08 11:51:58
 * @FilePath: \mysticism-mud\inherit\property.c
 * @Description: 物品基类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <ansi.h>

inherit _NAME;
inherit _MESSAGE;
inherit _MOVE;
inherit CORE_STD_TEST;

protected mapping property;
//是否可以移动ROOM
protected int property_move = 0;
//是否可以拾取
protected int property_get = 0;
//是否默认可见
protected int property_visible = 1;



int is_move()
{
    return property_move;
}

int is_get()
{
    return property_get;
}

int is_visible()
{
    return property_visible;
}


// 设置属性值
mixed set(string pron, mixed value)
{
    if (!mapp(property))
        property = ([]);
    return property[pron] = value;
}

// 获取属性值
mixed query(string pron)
{
    int data;
    data = property[pron];
    return data;
}

void set_property_init(int move,int get,int visible,string* id,string name)
{
    property_move = move;
    property_get = get;
    property_visible = visible;
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