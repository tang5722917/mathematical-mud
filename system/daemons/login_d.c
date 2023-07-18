/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-18 05:04:58
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
    write("\n游戏日历：" + TIME_D->game_time_description());
    write("\n^_^!请输入你的登录ID:");
    input_to("get_id", ob);
}

// 进入游戏
void enter_world(object ob, object user)
{
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
    user->bag_storage_init();   //玩家个人存储物品初始化
    user->home_init();          //玩家个人房间初始化
    user->money_init();         //玩家个人钱币初始化
    user->save(); // 保存玩家数据
    user->start_condition(file_name(SYS_OBJECT("start_mxp")),2,1);
    user->version_boardcast();
    user->move(user->query("space_room"));
    tell_room(start_room, user->short() + "连线进入这个世界。\n", ({user}));
}
