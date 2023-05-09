/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 14:35:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 18:04:50
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
            return load_object(ob2[0]->combat_script(env,rank));
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
        str = copy(fight_info[0]);
        fight_info -= ({fight_info[0]});
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

void print_info(string s)
{
    message("Combat",s,this_object()->get_player1());
}

void destruct_ob()
{
    foreach(object o in ob1_data){destruct(o);}
    foreach(object o in ob2_data){destruct(o);}
    foreach(object o in ob_summon){o->remove();}
    put_card_queue->remove();
    destruct(this_object());
}

void perform(F_INFO msg)
{   
    object o1,o2,ob_user;
    err->is_living(msg->ob1);
    o1 = msg->ob1;
    if(msg->ob2 != 0){
        err->is_living(msg->ob2);
        o2 = msg->ob2;
    }
    ob_user = this_object()->get_ob_data(o1);
    switch(msg->act)
    {
        case ENT:
            ob_user ->add_entity(msg->status);
            break;
        case MYS:
            ob_user->add_mystic(msg->status);
            ob_user->update_mystic();
            ob_user->update_card_q();
            break;
        case SUM:
            break;
        case PUT:
            load_object(PER_CARD_D)->perform(o1,msg->status,this_object());
            break;
        case ACT:
            break;
        case ENT_R:
            this_object()->get_ob_data(msg->ob1)->remove_entity(msg->status);
            break;
        case MYS_R:
            ob_user->delete_mystic(msg->status);
            ob_user->update_mystic();
            break;
        case SUM_R:
            break;
        default: break;
    }
}
