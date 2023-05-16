/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 19:43:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 13:21:54
 * @FilePath: \mysticism-mud\inherit\combat\combat_data.c
 * @Description: 战斗数据基础类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 
#include <combat.h> 
inherit _CLEAN_UP;

//战斗过程信息
nosave protected mixed *fight_info;
//出牌队列
nosave protected mixed put_card_queue;
//公共物品队列
nosave protected object *env_obj;
//战斗双方living 队列
nosave protected object *ob1_data,*ob2_data,err;
//战场召唤物序列
nosave protected object *ob_summon1,*ob_summon2;
//执行一条战斗指令

int length_ob_summon1(){return sizeof(ob_summon1);}
int length_ob_summon2(){return sizeof(ob_summon2);}
int length_env_obj(){return sizeof(env_obj);}
object *get_ob_summon1(){return ob_summon1;}
object *get_ob_summon2(){return ob_summon2;}
object *get_ob_env(){return env_obj;}

void *remove_summon1(object ob){ob_summon1-=({ob});}
void *remove_summon2(object ob){ob_summon2-=({ob});}
void *remove_env_obj(object ob){env_obj-=({ob});}
object get_summon_data(int type)
{
    if(type == 1)
    {
        return ob_summon1[0];
    }
    else
    {
        return ob_summon2[0];
    }
}

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
    //debug_message(f->str);  //查看行为序列
}
//在出牌序列添加一张牌
void add_put_card(object card,object user,int speed)
{
    P_CARD p;
    if(!put_card_queue)
        put_card_queue = new(_QUEUE,file_name(user)+"put_card");
    p = new(P_CARD,card:card,user:user,speed:speed);
    put_card_queue->push(p);
}

int put_card_sort(P_CARD p1,P_CARD p2)
{
    if((p1->speed) < (p2->speed)) return 1;
    else if(p1->speed == p2->speed) return 0;
    else return -1;
}
//对出牌序列进行排序，按照speed从大到小
void sort_put_card_queue()
{
    put_card_queue->sort("put_card_sort",this_object());
}

//得到出牌序列中speed最高的牌
P_CARD get_put_card()
{
    if((put_card_queue != 0) && (put_card_queue->length()>0))
    {
        return put_card_queue->pop();
    }
    else return 0;
}
//清空出牌序列
void clear_card_query(){put_card_queue->clear();}

int length_fight_info(){return sizeof(fight_info);}
void clear_fight_info(){fight_info = ({});}
//新建一个战斗living 数据
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
    ob = load_object(s);
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
