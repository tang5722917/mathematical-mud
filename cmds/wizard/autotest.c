/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-27 17:21:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-06-28 19:20:31
 * @FilePath: \mysticism-mud\cmds\wizard\autotest.c
 * @Description: driver自动测试命令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 

inherit CORE_CLEAN_UP;

int help(object me);

int test_arg(string arg)
{
    string * strs,*test_data;
    strs = pcre_match_all(arg,"\\D" );
    if(sizeof(strs))
        return 0;
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
    if(me->query("autotest"))
    {
        write("开始进行MUD 测试\n");
        if(stringp(arg))
        {
            if(arg == "all")
                write("将要进行MUD完整测试集测试\n");
            else if(test_arg(arg)){
                write("将要进行"+arg+"号测试\n");
                test_ob = load_object(TEST_DATA + arg);
                test_ob->test_main();
            }
            else
                write("请输入有效测试内容\n");
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
HELP );
    return 1;
}
