/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-11 13:22:42
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 03:48:11
 * @FilePath: /mysticism-mud/system/daemons/combat_d.c
 * @Description:  战斗守护类
 *                每一场战斗由此对象建立
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;
#include <combat.h>
#include <ansi.h>

//战斗计时(秒)
protected nosave int fight_time;
//战斗回合
protected nosave int fight_round;
//是否出过手牌
protected nosave int is_put;

//战斗对象
protected nosave object combat,script;

varargs void create(object *ob1,object *ob2,int fight_type,object env)
{
    fight_time=0;
    fight_round=0;
    if((ob1 !=0) && (ob2!=0))
    {
        message("FIG",BRED"                                                      "NOR+"\n"+
                      BRED"                       开始战斗！                     "NOR"\n"
                      BRED"                                                      "NOR,
        ob1+ob2);
    }
    else return ;
    if(fight_type == FIGHT_PVE){    //单个玩家对抗单个NPC PVE战斗
    //ob1玩家   ob2 NPC
    if((sizeof(ob1)==1) &&(sizeof(ob2)==1))
    {
        if(env != 0 && ob2[0]->combat_env() != 0)
        {
            ob1 ->start_fight(this_object());
            combat = new(ob2[0]->combat_env());
            combat->init(ob1[0],ob2[0],env);
            script = combat->set_combat_script(ob1,ob2,fight_type,env);
        }
        else return;
    }
    else             //多人PVE战斗
    {
        if(env != 0 && ob2[0]->combat_env() != 0)
            combat = new(ob2[0]->combat_env(),CORE_STD_FIGHT_M,ob1,ob2,env);
        else return;
    }}
    else {   // PVP 战斗
        ;  //TBD
    }
    combat->fight_init(script);
    set_heart_beat(1);
}

void destruct_ob()
{
    combat->msg_end();
    combat->destruct_ob();
    destruct(this_object());
    return;
}

//处理一个战斗过程
//返回值为0，表示战斗结束
//非0值表示战斗回合数
int combat_event(object fig)
{
    F_INFO str;
    str = fig->get_one_fight();
    if(str != 0){
        fig->print_fight(str);
        if (str->str == "本回合结束")
        {
            if( fight_round > 0)
                script->combat_event_round(combat);
            script->combat_process_round(fight_round,combat);
            fight_round += 1;
            is_put = 1;
        }
        if((fig->length_fight_info() == 0) && is_put)
        {
            fig->print_fight_UI(combat->fight_main_UI(fight_time,fight_round));
            fig->next_round(fight_round);
            is_put = 0;
        }
    }
    return fight_round+1;
}

void heart_beat( void )
{
    if(fight_time >= 0)
        fight_time += 1;  //时间加1s
    script->combat_process(fight_time,fight_round,combat);
    if ((combat_event(combat) == 0) && (fight_time > 1))
    {
        combat->fight_end();
        fight_time = -1;
    }
    script->combat_process_time(fight_time,combat);
    if((combat->length_fight_info() == 0 ) &&(fight_time < 0 ))
    {
        set_heart_beat(0);
        destruct_ob();
        return;
    }
}

object combat_object()
{
    return combat;
}

void combat_end()
{
    fight_round = -1;
}

//调用出牌判定静态类处理出牌动作
int put_card_d(int *n_card,object user)
{
    object o;
    o = load_object(PUT_CARD_D);
    if(n_card == 0)
    {
        o->put_card_d_pass(combat);
        return 1;
    }
    o->put_card(combat,n_card,user);
    return 1;
}
//获取user手牌数量
int get_card_num(object user)
{
    return combat->get_card_num(user);
}
