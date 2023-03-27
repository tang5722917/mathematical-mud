/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:06:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-27 15:38:37
 * @FilePath: \mysticism-mud\World\base\card\01\paper_replace.c
 * @Description:  纸人替身牌
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#include <ansi.h>
#include <mxp.h>
inherit CORE_STD_CARD;

string card_name(){return "纸人替身";}
string card_explain(){return "放置一个生命为1的纸人，抵挡一次攻击";}
