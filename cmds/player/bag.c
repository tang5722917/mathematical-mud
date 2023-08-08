/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-04 20:04:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-08 18:24:55
 * @FilePath: \mysticism-mud\cmds\player\bag.c
 * @Description: 查看背包指令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <ansi.h>
#include <mxp.h>
#include <bag.h>
inherit CORE_CLEAN_UP;
inherit _MXP;

int help(object me)
{
    write(@KNOW
指令格式 : bag(b) + [类型]
bag/b 展示所有身上携带物品
"bag(b) yao" 仅展示身上携带药剂
[类型] 有如下几种
yao  --  药剂
fu   --  符咒
food --  食品
pu   --  普通物品
cai  --  各种原始材料
mys  --  非凡物品
task --  任务物品
spc  --  特殊物品
KNOW );
    return 1;
}

string show_bag(string *bag)
{
    string msg="";
    int bag_sum = 0;
    int bag_use = 0;
    string bag_status =BGRN "正常" NOR;
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf("%-40s%-10s\n", "背包总容量/已用容量:" + bag_sum +" / "+ bag_use, "状态："+bag_status);
    return msg;
}

int main(object me, int arg )
{
    string *bag ,msg="";
    bag = me->
    if( MXP_USER(me) )
        msg ="<!ELEMENT UI FLAG='UI'>\n<UI>";
    msg += show_bag(bag);
    if(MXP_USER(me))
        msg += "</UI>";
    MXP_message("Status",msg,me);
    return 1;
}
