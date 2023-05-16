/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-12 17:16:19
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 09:13:59
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\combat_judge_d.c
 * @Description: 战斗结果判定
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>

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

int is_hp_empty(object summon)
{
    if(summon->get_hp() > 0) return 0;
    else return 1;
}

string summon_check(object combat)
{
    string str = "";
    if(combat->length_env_obj())
    {}
    if(combat->length_ob_summon1())
    {
        foreach(object s in combat->get_ob_summon1()){
            if(is_hp_empty(s)){
                combat->remove_summon1(s);
                str += BYEL+ s->user_name()+"的"+s->name()+"消失了"+NOR;
            }
        }
    }
    if(combat->length_ob_summon2())
    {
        foreach(object s in combat->get_ob_summon2()){
            if(is_hp_empty(s)){
                combat->remove_summon2(s);
                str += BBLU + s->user_name()+"的"+s->name()+"消失了"+NOR;
            }
        }
    }
    return str;
}


//0 战斗未结束 1 ob1 获胜  2 ob2获胜  3平局
string *perform_combat_judge(object combat)
{
    string str="";
    str += summon_check(combat);
    if(hp_check_user( ({combat->get_ob2_data()}) ) )
    {
        perform_combat_result(combat,1);
        str += combat->win_str1();
        return ({1,str});
    }
    if(hp_check_user( ({combat->get_ob1_data()}) ) )
    {
        perform_combat_result(combat,2);
        str += combat->win_str2();
        return ({2,str});
    }
    return ({0,str});
}
