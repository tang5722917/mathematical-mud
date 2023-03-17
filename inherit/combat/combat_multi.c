/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-17 14:47:51
 * @FilePath: \mysticism-mud\inherit\combat\combat_multi.c
 * @Description:  多人战斗基类
 *                提供多人战斗的UI
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

inherit INHERIT_PATH "combat/combat_base";
#include <ansi.h>

nosave protected object * obs1=({});
nosave protected object * obs2=({});
