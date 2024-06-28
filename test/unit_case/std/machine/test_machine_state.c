/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2024-05-31 20:37:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-06-28 19:19:03
 * @FilePath: \mysticism-mud\test\unit_case\std\machine\test_machine_state.c
 * @Description: 
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include "/lpc_atest/lpc_atest.h"
#include <machine.h>

inherit LPC_ATEST_PATH "lpc_atest_unit";
inherit _STATE;
inherit _STATE_M;

int test_state_interface()
{
    this_object()->init("unit_test");
    TEST_ASSERT_EQUAL_LOGIC(1,this_object()->is_state_name("unit_test"));
}

int test_machine_interface()
{
    object ob1,ob2,ob3;
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
    ob1 = new_state(state1);
    ob2 = new_state(state2);
    ob3 = new_state(state3);
    this_object()-> machine_init( ({ob1,ob2,ob3}) );
    TEST_ASSERT_EQUAL_INT(3,this_object()->get_size_state());
}

int main()
{
    ATEST_BEGIN();
    RUN_TEST("test_state_interface");
    RUN_TEST("test_machine_interface");
    ATEST_END();
}

string info(){
    return "状态机状态基类接口测试" ;
}
