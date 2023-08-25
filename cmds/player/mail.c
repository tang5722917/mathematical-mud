/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-25 17:55:24
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-25 20:09:26
 * @FilePath: \mysticism-mud\cmds\player\mail.c
 * @Description: 查看邮箱邮件列表指令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <mxp.h>

inherit CORE_CLEAN_UP;
inherit _MXP;

int help(object me)
{
    write(@KNOW
指令格式 : mail(ma)
mail(ma)               显示当前所有的邮件信息
mail(ma) all           详细查看当前领取的所有任务
mail     delete all    删除所有已读邮件
mail(ma) 【数字】       查看对应编号邮件详细情况
KNOW );
    return 1;
}

 string show_mail(string *ma)
 {
     string msg="";
     int ma_sum = 0;
     int ma_use = MYSTIC_MAX_MAIL;
     string ma_status =BGRN "正常" NOR;
     msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
     msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
     msg += sprintf("%-40s%-10s\n", "收到邮件总数/MAX邮件数:" + ma_sum +" / "+ ma_use, "状态："+ma_status);
     return msg;
 }
 
 int main(object me, int arg )
 {
     string *ma ,msg="";
     ma = me->get_mail_list();
     if( MXP_USER(me) )
         msg ="<!ELEMENT UI FLAG='UI'>\n<UI>";
     msg += show_mail(ma);
     if(MXP_USER(me))
         msg += "</UI>";
     MXP_message("Status",msg,me);
     return 1;
 }
