/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-25 17:55:24
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-25 19:59:58
 * @FilePath: \mysticism-mud\cmds\player\quest.c
 * @Description: 任务列表指令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <mxp.h>

inherit CORE_CLEAN_UP;
inherit _MXP;

int help(object me)
{
    write(@KNOW
指令格式 : quest(qu)
quest(qu)         显示当前所有领取的任务
quest(qu) all     详细查看当前领取的所有任务
quest(qu) 【数字】 查看对应编号任务的详细情况
KNOW );
    return 1;
}

 string show_quest(string *qu)
 {
     string msg="";
     int qu_sum = 0;
     int qu_use = MYSTIC_MAX_QUEST;
     string qu_status =BGRN "正常" NOR;
     msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
     msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
     msg += sprintf("%-40s%-10s\n", "已领取任务数/MAX任务数:" + qu_sum +" / "+ qu_use, "状态："+qu_status);
     return msg;
 }
 
 int main(object me, int arg )
 {
     string *qu ,msg="";
     qu = me->get_quest_list();
     if( MXP_USER(me) )
         msg ="<!ELEMENT UI FLAG='UI'>\n<UI>";
     msg += show_quest(qu);
     if(MXP_USER(me))
         msg += "</UI>";
     MXP_message("Status",msg,me);
     return 1;
 }
