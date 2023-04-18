/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 14:35:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-18 19:46:49
 * @FilePath: \mysticism-mud\inherit\combat\combat_base.c
 * @Description:战斗基类
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <mxp.h>
#include <combat.h>

inherit INHERIT_PATH "combat/combat_data";
inherit CORE_STD_TEST;

varargs object set_combat_script(object *ob1,object *ob2,int fight_type,object env,int rank)
{
    if(fight_type == FIGHT_PVE)   //PVE
    {
        if((sizeof(ob1)==1) &&(sizeof(ob2)==1))  //1V1 PVE
        {
            return find_object(ob2[0]->combat_script(env,rank));
        }
    }
}

string fight_main_UI(int fight_time,int fight_round){return "";}

//战斗开始时，第0回合，初始接口
int fight_init(object script){return 0;}
//结束战斗
int fight_end(){return 0;}

//从动作序列中取出一条
F_INFO get_one_fight()
{
    F_INFO str;
    if(sizeof(fight_info) != 0)
    {
        str = fight_info[0];
        fight_info -= ({str});
        return str;
    }
    else return 0;
}

int is_quit_fight()
{
    //返回1表示战斗可以退出,0 无法退出
#ifdef DEBUG_MYSTICISM
    return 1;
#else 
    return is_quit_combat()
#endif
}

void destruct_ob()
{
    foreach(object o in ob1_data){destruct(o);}
    foreach(object o in ob2_data){destruct(o);}
    destruct(this_object());
}

void perform(F_INFO msg)
{   
    object o1,o2;
    err->is_living(msg->ob1);
    o1 = msg->ob1;
    if(msg->ob2 != 0){
        err->is_living(msg->ob2);
        o2 = msg->ob2;
    }
    switch(msg->act)
    {
        case ENT:
            if(msg->ob1 == ob1)
                ob1_data->add_entity(msg->status);
            else
                ob2_data->add_entity(msg->status);
            break;
        case MYS:
            o1->add_mystic(msg->status);
            o1->update_mystic();
            break;
        case PUT:
            break;
        case ACT:
            break;
        case ENT_R:
            break;
        case MYS_R:
            o1->delete_mystic(msg->status);
            o1->update_mystic();
            break;
        default: break;
    }
}
