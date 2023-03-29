/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-28 21:36:18
 * @FilePath: \mysticism-mud\system\daemons\login_d.c
 * @Description: 
 * 
 * Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved. 
 */
inherit CORE_LOGIN_D;
#include <ansi.h>

protected void welcome(object ob)
{
    color_cat(MOTD);
    write("\n                               版本"VERSION);
    write("\n^_^!请输入你的登录ID:");
    input_to("get_id", ob);
}

// 进入游戏
void enter_world(object ob, object user)
{
    object MXP_Init;
#ifdef START_ROOM
    string start_room = START_ROOM;
#else
    string start_room = VOID_OB;
#endif
    user->set_temp("login_ob", ob);
    ob->set_temp("user_ob", user);
    if (interactive(ob))
        exec(user, ob);

    user->setup(); // 激活玩家角色
    user->set("last_login_ip", ob->query_temp("ip_number"));
    user->set("last_login_at", time());
    user->set("last_saved_at", time());
    user->add("login_times", 1);
    MXP_Init = load_object("/World/00/start_mxp");
    user->start_condition(file_name(MXP_Init),5,1);
    user->save(); // 保存玩家数据

    user->move(start_room);
    tell_room(start_room, user->short() + "连线进入这个世界。\n", ({user}));
}
