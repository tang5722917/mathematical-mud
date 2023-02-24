/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-02-25 04:51:53
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

// 根据ID初始化玩家对象
object make_body(object ob)
{
    object user;

    user = new(USER_OB);

    if (!user)
    {
        write(RED "\nUSER_OB 出现异常，无法初始化你的角色。\n" NOR);
        return 0;
    }

    seteuid(ob->query("id")); // 设置当前对象 euid 为玩家ID
    export_uid(user); // 设置玩家 uid
    seteuid(getuid()); // 设置当前对象 euid 为对象uid
    user->set("id", ob->query("id"));
    user->init_status(getuid());
    return user;
}