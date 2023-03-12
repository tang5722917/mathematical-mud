/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-11 13:22:42
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-13 03:09:46
 * @FilePath: \mysticism-mud\system\daemons\combat_d.c
 * @Description:  战斗守护类
 * 
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;

#include <ansi.h>

#define FIGHT_PVE 0
#define FIGHT_PVP 1

//战斗计时(秒)
protected nosave int fight_time=0;
//战斗回合
protected nosave int fight_round=0;


//战斗对象
protected nosave object combat;

varargs void create(object *ob1,object *ob2,int fight_type,object env)
{
    fight_time=0;
    fight_round=0;
    if((ob1 !=0) && (ob2!=0))
    {
        message("FIG",BRED "                                               
                开始战斗！                     
                                               " NOR,ob1+ob2);
    }
    else return ;
    if(fight_type == FIGHT_PVE){    //单个玩家对抗单个NPC PVE战斗
    //ob1玩家   ob2 NPC
    if((sizeof(ob1)==1) &&(sizeof(ob2)==1))
    {
        if(env != 0 && ob2[0]->combat_env() != 0)
        {
            ob1 ->start_fight();
            combat = new(ob2[0]->combat_env(),ob1[0],ob2[0],env);
        }
        else return;
    }
    else
    {
        if(env != 0 && ob2[0]->combat_env() != 0)
            combat = new(ob2[0]->combat_env(),CORE_STD_FIGHT_M,ob1,ob2,env);
        else return;
    }}
    else {   // PVP 战斗
        ;  //TBD
    }
    combat->fight_init();
    set_heart_beat(1);
}

//处理一个战斗过程
//返回值为0，表示战斗结束
//非0值表示战斗回合数
int combat_event(object fig)
{
    string str;
    str = fig->print_one_fight();
    if(str != 0){
        fig->print_fight(str);
        if (str == "End One Round")
        {
            fig->print_fight(combat->fight_main_UI(fight_time,fight_round));
            fig->next_round();
        }
    }
    fight_round += 1;
    return fight_round;
}

void heart_beat( void )
{
    fight_time += 1;  //时间加1s
    if (combat_event(combat) == 0)
    {
        combat->fight_end();
        destruct(this_object());
    }
}




