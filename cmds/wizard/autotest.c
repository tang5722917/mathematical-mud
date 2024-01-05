/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-27 17:21:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-05 19:29:40
 * @FilePath: \mysticism-mud\cmds\wizard\autotest.c
 * @Description: driver自动测试命令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 
#include <test.h>
inherit CORE_CLEAN_UP;

int help(object me);

int test_perform_arg(string arg,object me)
{
    object test_ob =load_object(AUTOTEST_OB);
    string *test_arg = explode( arg, " " );
    return test_ob->perform(test_arg,me);
}

int is_test_arg(string arg)
{
    object test_ob =load_object(AUTOTEST_OB);
    string *test_arg = explode( arg, " " );
    if(test_ob->check_ins(test_arg[0],sizeof(test_arg)-1))
        return 1;
    return 0;
}

string test_arg(string arg,object me)
{

    if(!is_test_arg(arg))
        return "测试指令错误";
    if(test_perform_arg(arg,me))
        return "autotest成功执行";
    else return "指令执行错误";

}

int main(object me, string arg)
{
    object test_ob;
    string str;
    string test_feedback;
    if(me->query("autotest"))
    {
        if(stringp(arg))
        {
            test_feedback = test_arg(arg,me);
            write(test_feedback + "\n");
        }
        else{
            write("非法测试指令\n");
            return 1;
        }
    }
    else {
            write("当前账号并非游戏测试账号\n");
            return 1;
    }
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;
    write(@HELP
指令格式: autotest + 【功能项】+【string】
关于autotest中【string】为参数变量，格式为 前缀+变量字符串，eg:
str_【字符串变量】,int_【整型变量】,obj_【对象变量】

autotest  dbase 【prop】【value】 完成对user dbase中prop属性value的更改
autotest  update  完成存档修改并重新载入玩家对象
HELP );
    return 1;
}
