/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-04 16:40:29
 * @FilePath: \mysticism-mud\inherit\combat\combat_data.c
 * @Description: 战斗数据基础类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 
#include <combat.h> 
inherit _CLEAN_UP;

//战斗过程信息
nosave protected mixed *fight_info;
//公共物品队列
nosave protected object *env_obj;
//战斗双方living 队列
nosave protected object *ob1_data,*ob2_data,err;
//战场召唤物序列
nosave protected object *ob_summon;
//执行一条战斗指令
varargs void add_f_ins(string str, object ob1,int act,object status,object ob2)
{
    F_INFO f;
    if(!act) //只有描述，没有具体的行为
        f = new(F_INFO,str:str,ob1:ob1,status:0,act:0,ob2:ob2);
    else{   //存在动作
            err->object_missing(status);
            f = new(F_INFO,str:str,ob1:ob1,status:status,act:act,ob2:ob2);
    }
    fight_info +=({f});
}

F_INFO f_info_copy(F_INFO f){
    return new(F_INFO,str:f->str,ob1:f->ob1,status:f->status,act:f->act,ob2:f->ob2);}

int length_fight_info(){return sizeof(fight_info);}

object add_new_fighter(object ob_user)
{
    object ob;
    ob = new(FIG_DATA);
    ob->init(ob_user);
    return ob;
}
//只有描述的战斗指令，用于战斗中的对话/说明等用途
varargs void add_f_info(string s,object o)
{
    add_f_ins(s, o, None);
}

//获得手牌/手牌/状态/物品/召唤物等
void add_f_ent(string s,object o)
{
    string str="";
    object ob;
    ob = find_object(s);
    err->is_entity(ob);
    if( inherits(CORE_STD_CARD,ob)  )
        str += "获得手牌 ";
    else if( inherits(CORE_STD_EQUIP,ob)  )
        str += "获得召唤物 ";
    else if( inherits(CORE_STD_SUMMON,ob)  )
        str += "获得装备 ";
    else if( inherits(CORE_STD_STATUS,ob)  )
        str += "获得状态 ";
    add_f_ins(str, o,ENT, ob);
}

//失去手牌/手牌/状态/物品/召唤物等
void remove_f_ent(string s,object o)
{
    string str="";
    object ob;
    ob = find_object(s);
    err->is_entity(ob);
    if( inherits(CORE_STD_CARD,ob)  )
        str += "失去手牌 ";
    else if( inherits(CORE_STD_EQUIP,ob)  )
        str += "失去召唤物 ";
    else if( inherits(CORE_STD_SUMMON,ob)  )
        str += "失去装备 ";
    else if( inherits(CORE_STD_STATUS,ob)  )
        str += "失去状态 ";
    add_f_ins(str, o, ENT_R, ob);
}

//使用手牌
void put_f_ent(string s,object o)
{
    string str="";
    object ob;
    ob = find_object(s);
    err->is_entity(ob);
    if( inherits(CORE_STD_CARD,ob)  )
    {
        str += "使用手牌 ";
        add_f_ins(str, o, PUT, ob);
    }
}
