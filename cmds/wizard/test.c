/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-05-29 19:02:25
 * @FilePath: \mysticism-mud\cmds\wizard\test.c
 * @Description: 用于临时测试
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 

inherit CORE_CLEAN_UP;
#include <machine.h>

int help(object me);

int main(object me, string arg)
{
    string str;
    object ob1,ob2,ob3,ma;
    mapping state1 =([
        "name": "solid",
        "on_enter":"say_hello",
        "on_exit":"say_goodbye"
    ]);
    mapping state2 =([
        "name": "liquid",
        "on_enter":"say_hello",
        "on_exit":"say_goodbye"
    ]);
    mapping state3 =([
        "name": "gas",
        "on_enter":"say_hello",
        "on_exit":"say_goodbye"
    ]);
    mixed * switch_stat =({
        (["trigger" : "melt" ,       "source" : "solid",  "dest": "liquid"]),
        (["trigger" : "evaporate" ,  "source" : "liquid", "dest": "gas"]),
        (["trigger" : "sublimate" ,  "source" : "solid",  "dest": "gas"])
    });
    ob1 = new_state(state1);
    ob3 = new_state(state2);
    ob2 = new_state(state3);
    ma = new(_STATE_M);
    ma-> machine_init( ({ob1,ob2,ob3}) );
    ma->machine_build(switch_stat);
    debug_message(ma->get_current_state()->state_info());
    ma->trigger("melt");
    debug_message(ma->get_current_state()->state_info());
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: test
用于临时测试
HELP );
        return 1;
}
