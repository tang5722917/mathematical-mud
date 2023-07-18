/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-18 05:26:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-18 05:36:50
 * @FilePath: \mysticism-mud\cmds\player\wallet.c
 * @Description: 
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <mxp.h>
inherit CORE_CLEAN_UP;

int help(object me)
{
    write(@KNOW
指令格式 : wallet(wa)
打开钱包查看当前拥有的货币
KNOW );
    return 1;
}

string show_wallet(void)
{
    string msg="";
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    return msg;
}

int main(object me, int arg )
{
    string msg = "";
    if( MXP_USER(me) )
        msg ="<!ELEMENT UI FLAG='UI'>\n<UI>";
    msg += show_wallet();
    if(MXP_USER(me))
        msg += "</UI>";
    MXP_message("Status",msg,me);
    return 1;
}
