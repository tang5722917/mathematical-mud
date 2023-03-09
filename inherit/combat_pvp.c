/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 15:13:33
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-09 15:14:58
 * @FilePath: \mysticism-mud\inherit\combat_p2p.c
 * @Description: P2P人战斗基类
 *               提供P2P战斗的UI
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

 inherit INHERIT_PATH "combat_base";
#include <ansi.h>

nosave protected object ob1;
nosave protected object ob2;

void create(object o1,object o2)
{
    ob1 = o1;
    ob2 = o2;
}