/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-04 11:43:47
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-19 17:39:12
 * @FilePath: \mysticism-mud\World\base\world_base_create.c
 * @Description: 游戏全局资源预加载
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <game_world.h>
inherit CORE_STD_PRE;

protected object *ob_mystic,*ob_card,*ob_skill;

string ob_name()
{
    return "游戏基础资源对象";
}

 void create()
 {
    ob_mystic = load_path_object(MYSTIC_PATH);
    debug_message("[" + ctime() + "]成功加载非凡特性对象数："+sizeof(ob_mystic));
    ob_card = load_path_object(MYSTIC_CARD);
    debug_message("[" + ctime() + "]成功加载卡片对象数："+sizeof(ob_card));
    ob_skill = load_path_object(MYSTIC_SKILL);
    debug_message("[" + ctime() + "]成功加载技能对象数："+sizeof(ob_skill));
    ob_load_end(1);
 }
