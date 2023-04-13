/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-14 17:52:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-13 18:40:01
 * @FilePath: \mysticism-mud\World\00\combat\start_up_fight.c
 * @Description: 新手引导的战斗对象
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <game_world.h> 
inherit CORE_STD_FIGHT_S;

mixed * fight_init_user(object user)
{   
    mixed * str=({});
    str +=({({"突然感觉体内涌现一股神秘的力量！",user})});
    str +=({({"同时脑海中有一个清晰的声音响起——“你要准备开始战斗”",user})});
    return str;
}

mixed * fight_init_env(object env)
{
    mixed * str=({});
    str +=({({"模糊的人影抬起头注视着你",env})});
    return str;
}

mixed * fight_end_user(object user)
{
    return ({({"感到身上的力量衰退了\n",user})});
}

//定义电脑的战斗结束时行为
mixed * fight_end_env(object env)
{
    return ({({"身影缓缓消失\n",env})});
}
