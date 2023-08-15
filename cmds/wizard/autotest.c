/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-27 17:21:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-14 14:44:15
 * @FilePath: \mysticism-mud\cmds\wizard\autotest.c
 * @Description: driver自动测试命令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 
#include <test.h>
inherit CORE_CLEAN_UP;

int help(object me);

void test_perform_arg(string arg,object me)
{
    object test_ob =load_object(AUTOTEST_OB);
    string *test_arg = explode( arg, " " );
    test_ob->perform(test_arg,me);
}

int is_test_arg(string arg)
{
    object test_ob =load_object(AUTOTEST_OB);
    string *test_arg = explode( arg, " " );
    if(test_ob->check_ins(test_arg[0],sizeof(test_arg)-1))
        return 1;
    write("测试指令错误");
    return 0;
}

int test_arg(string arg)
{
    string * strs,*test_data;
    strs = pcre_match_all(arg,"\\D" );
    if(sizeof(strs))
    {
        if(is_test_arg(arg))
            return 2;
        else return 0;
    }
    else
    {
        test_data = get_dir(TEST_DATA);
        foreach (string s in test_data)
        {
            if(s == (arg + ".c"))
                return 1;
        }
        return 0;
    }
}

int main(object me, string arg)
{
    object test_ob;
    string str;
    int test_fun;
    if(me->query("autotest"))
    {
        write("开始进行MUD 测试\n");
        if(stringp(arg))
        {
            if(arg == "all")
                write("将要进行MUD完整测试集测试\n");
            else {
                test_fun = test_arg(arg);
                if(test_fun == 1){
                    write("将要进行"+arg+"号测试\n");
                    test_ob = load_object(TEST_DATA + arg);
                    test_ob->test_main(me);
                }
                else if(test_fun == 2){
                    test_perform_arg(arg,me);
                }
                else
                    write("请输入有效测试内容\n");
            }
        }
        else
        {
            write("请输入测试内容\n");
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
指令格式: autotest + 【all/数字】
autotest all 完成全部测试
autotest 【数字】 进行指定测试
关于autotest中【】为参数变量，格式为 前缀+变量字符串，eg:
str_【字符串变量】,int_【整型变量】,obj_【对象变量】
autotest  dbase 【prop】【value】 完成对user dbase中prop属性value的更改
autotest  update  完成存档修改并重新载入玩家对象
HELP );
    return 1;
}
