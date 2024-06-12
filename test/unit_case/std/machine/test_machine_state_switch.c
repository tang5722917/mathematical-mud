/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2024-05-31 18:10:51
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-06-12 19:39:12
 * @FilePath: \mysticism-mud\test\unit_case\std\machine\test_machine_state_switch.c
 * @Description: 
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit LPC_ATEST_PATH "lpc_atest_unit";
#include <machine.h>
#include "/lpc_atest/lpc_atest.h"

int test_state_switch()
{
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
    TEST_ASSERT_EQUAL_STRING(ma->get_current_state()->state_info(),"");
    ma->trigger("melt");
    TEST_ASSERT_EQUAL_STRING(ma->get_current_state()->state_info(),"");

    return 1;
}

int main() {
    ATEST_BEGIN();
    RUN_TEST("test_state_switch");
    ATEST_END();
}

string info(){
    return "状态机状态转换测试" ;
}
