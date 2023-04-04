/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 14:35:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 16:42:04
 * @FilePath: \mysticism-mud\inherit\combat\combat_base.c
 * @Description:战斗基类
 *              提供战斗效果/结果的判定框架
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
#include <mxp.h>
#include <combat.h>

inherit INHERIT_PATH "combat/combat_data";


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

string print_one_fight()
{
    string str;
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


//结束战斗
int fight_end(object ob)
{  
}
