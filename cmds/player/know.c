/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-27 18:17:18
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-02-27 19:09:48
 * @FilePath: \mysticism-mud\cmds\player\know.c
 * @Description:  游戏中的知识界面
 *                包括冒险帮助与冒险经历
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;
#include <ansi.h>
int know_commands(string command, object me);

int main(object me, string arg)
{
    object file;
    me->disable_living();
    write("请输入查看的内容：\n") ;
    input_to("know_commands",me);
    me->enable_living();
    return 0;
}

int know_commands(string command, object me)
{
    if(command =="q")
    {
        write("结束对已了解神秘知识的查看\n") ;
        return 2;
    }
    write("请输入继续查看的内容：\n") ;
    input_to("know_commands",me);
    return 0;
}