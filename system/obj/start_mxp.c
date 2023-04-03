/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-28 00:12:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-03 11:58:10
 * @FilePath: \mysticism-mud\system\obj\start_mxp.c
 * @Description: 玩家登录MXP检查
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */
#include <mxp.h>

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
    mapping m;
    ob->set_mxp_enable(Enable_MXP);
    m = ob->QueryMXPVersion();
    if( (sizeof(m)== 0) && USER_MXP)
    {
        message("Info","当前客户端不支持MXP\n",ob);
        return;
    }
    else
        message("Info","当前客户端支持MXP\n",ob);
#ifdef DEBUG_MYSTICISM
    message("Info",m[1],ob);
#endif
    m = ob->QueryMXPSupportInfo();
#ifdef DEBUG_MYSTICISM
    if( sizeof(m)== 0)
    {
        return;
    }
    message("Info",m[1],ob);
#endif
}
