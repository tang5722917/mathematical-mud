/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-14 17:52:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 17:10:42
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗过程对象
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <game_world.h> 
inherit CORE_STD_FIGHT_S;

string * fight_init_user(object user)
{   
    object mys;
    string * str=({});
    str +=({"突然感觉体内涌现一股神秘的力量！"});
    mys = new(MYSTIC_PATH "other/mystic_init_help");
    user->add_mystic(mys);
    str +=({"同时脑海中有一个清晰的声音响起——“你要准备开始战斗”"});
    user->update_mystic();
    return str;
}
string * fight_init_env(object env)
{
    string * str=({});
    str +=({"模糊的人影抬起头注视着你"});
    return str;
}

string * fight_end_user(object user)
{   

    return ({"你感到身上的力量衰退了\n"});
}

