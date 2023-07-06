/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-04 20:04:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-06 16:51:43
 * @FilePath: \mysticism-mud\cmds\player\bag.c
 * @Description: 查看背包指令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <map.h> 
#include <game_world.h> 
inherit CORE_CLEAN_UP;

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
te   --  特殊物品
KNOW );
    return 1;
}

string show_bag(string *bag)
{
    string s="";
    return s;
}

int main(object me, int arg )
{
    string *bag = ({});
    show_bag(bag);
    return 1;
}
