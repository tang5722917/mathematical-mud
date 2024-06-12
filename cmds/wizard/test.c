/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-06-04 17:51:00
 * @FilePath: \mysticism-mud\cmds\wizard\test.c
 * @Description: 用于临时测试
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 

inherit CORE_CLEAN_UP;


int help(object me);

int main(object me, string arg)
{
    object ob = new(ATEST_D);
    ob->test_all();
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
