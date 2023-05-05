/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-17 14:14:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-05 14:27:04
 * @FilePath: \mysticism-mud\inherit\living\living_npc.c
 * @Description: 非人NPC基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit _LIVING;

void living_npc_setup()
{
    set_living_base_value(0,0,0,0,0,0,0,0,0);
    living_setup();
}

void add_mystic_npc(string str)
{
    add_mystic(load_object(str));
    update_mystic();
}
