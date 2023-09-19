/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-04 20:04:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-19 18:08:43
 * @FilePath: \mysticism-mud\cmds\player\task.c
 * @Description: 查看任务指令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <ansi.h>
#include <mxp.h>
#include <task.h>
inherit CORE_CLEAN_UP;
inherit _MXP;

int help(object me)
{
    write(@KNOW
指令格式 : task(t) + [类型]
task/t 展示所有正在进行的任务
"task(t) day" 仅显示日常任务
[类型] 有如下几种
main   --  主线任务
day    --  日常任务
org    --  所属势力任务
mys    --  非凡途径任务
skills --  技能任务
world  --  世界任务
com    --  通用任务
KNOW );
    return 1;
}

string show_task(string *task)
{
    string msg="";
    int task_sum = MYSTIC_MAX_QUEST;
    int task_use = 0;
    string task_status =BGRN "正常" NOR;
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf("%-40s%-10s\n", "最大任务数/正在进行任务数:" + task_sum +" / "+ task_use, "状态："+task_status);
    return msg;
}

int main(object me, int arg )
{
    string *task ,msg="";
    task = me->get_task_list();
    if( MXP_USER(me) )
        msg ="<!ELEMENT UI FLAG='UI'>\n<UI>";
    msg += show_task(task);
    if(MXP_USER(me))
        msg += "</UI>";
    MXP_message("Status",msg,me);
    return 1;
}
