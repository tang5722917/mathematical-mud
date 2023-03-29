/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-28 00:12:46
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-28 21:22:45
 * @FilePath: \mysticism-mud\World\00\start_mxp.c
 * @Description: 玩家登录MXP检查
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CONDITION_MOD;
inherit INHERIT_PATH "living/mxp_user" ;
string name="";
string type="";
string id="";
int time=1;

void heart_beat_effect(object ob)
{
    write("Hello World\n");
}
