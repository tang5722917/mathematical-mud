/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-28 00:12:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-30 16:21:48
 * @FilePath: \mysticism-mud\system\obj\start_mxp.c
 * @Description: 玩家登录MXP检查
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CONDITION_MOD;

string name="MXP测试";
string type="测试";
string id="000";

void start_effect(object ob)
{
    write("测试玩家MXP支持环境\n");
    ob->MXP_test_init();
}

void heart_beat_effect(object ob)
{
}

// 结束状态时的效果
void stop_effect(object ob)
{
    string s;
    s = ob->QueryMXPVersion()[1];
    message("Info",s,ob);
    s = ob->QueryMXPSupportInfo()[1];
    message("Info",s,ob);
}
