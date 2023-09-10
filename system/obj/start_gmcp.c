/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-28 00:12:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-10 02:33:58
 * @FilePath: \mysticism-mud\system\obj\start_gmcp.c
 * @Description: 玩家登录MXP检查
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */
#include <gmcp.h>

inherit _CONDITION_MOD;

string name="GMCP测试";
string type="测试";
string id="001";

void start_effect(object ob)
{
    write("\n测试玩家GUI支持环境\n");
}

void heart_beat_effect(object ob)
{
}

// 结束状态时的效果
void stop_effect(object ob)
{
    string gui_info="";
    mapping gmcp_info;
    message("Info","当前Mudlet客户端GUI满足游戏需求",ob);
    //if()
    //    message("Info","当前客户端不支持GMCP",ob);
#ifdef DEBUG_MYSTICISM
    gmcp_info = ob->get_gmcp_info();
    gui_info += "GUI Client平台：" + gmcp_info["client"] + "\n";
    gui_info += "GUI客户端名称：" + gmcp_info["gui"] + "\n";
    gui_info += "GUI客户端版本：" + gmcp_info["version"] + "\n";
    gui_info += "GUI客户端支持最大mud版本：" + gmcp_info["max_mud_version"] + "\n";
    gui_info += "GUI客户端支持最小mud版本：" + gmcp_info["min_mud_version"] + "\n";
    message("Info",gui_info,ob);
#endif
}
