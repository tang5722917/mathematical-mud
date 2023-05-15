/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-12 17:16:19
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-15 17:41:45
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\combat_judge_d.c
 * @Description: 战斗结果判定
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

int perform_combat_result(object combat,int result)
{
    object c;
    c = combat->get_player1()->fight_object();
    combat->clear_fight_info();
    c->combat_end();
    return 1;
}

int hp_check_user(object *user)
{
    foreach(object o in user)
        if(o->query_attr("hp") > 0)
            return 0;
    else return 1;
}

int summon_check(object combat)
{
    if(combat->length_env_obj())
    {}
    if(combat->length_ob_summon1())
    {}
    if(combat->length_ob_summon2())
    {}
}


//0 战斗未结束 1 ob1 获胜  2 ob2获胜  3平局
int perform_combat_judge(object combat)
{
    summon_check(combat);
    if(hp_check_user( ({combat->get_ob2_data()}) ) )
    {
        perform_combat_result(combat,1);
        return 1;
    }
    if(hp_check_user( ({combat->get_ob1_data()}) ) )
    {
        perform_combat_result(combat,2);
        return 2;    
    }
    return 0;
}
