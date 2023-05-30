/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 11:43:47
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-30 18:48:02
 * @FilePath: \mysticism-mud\World\base\world_base_create.c
 * @Description: 游戏全局资源预加载
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <game_world.h>
inherit CORE_STD_PRE;

protected object *ob_mystic,*ob_card,*ob_skill,*ob_summon,*ob_religion;

string ob_name()
{
    return "游戏基础资源对象";
}

 void create()
 {
    ::create();
    ob_mystic = load_path_object(MYSTIC_PATH,"非凡特性");
    ob_card = load_path_object(MYSTIC_CARD,"卡片");
    ob_summon = load_path_object(MYSTIC_SUMMON,"召唤物");
    ob_religion = load_path_object(MYSTIC_RELIGION,"非凡势力");
    //ob_skill = load_path_object(MYSTIC_SKILL,"技能");
    ob_load_end(1);
 }
