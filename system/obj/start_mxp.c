/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-28 00:12:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-29 15:55:09
 * @FilePath: \mysticism-mud\World\00\start_mxp.c
 * @Description: 玩家登录MXP检查
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CONDITION_MOD;
inherit INHERIT_PATH "living/mxp_user" ;

string name="计时器测试";
string type="测试";
string id="000";

void heart_beat_effect(object ob)
{
    write("Hello World\n");
}
