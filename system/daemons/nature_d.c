/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-25 11:27:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-25 16:17:17
 * @FilePath: \mysticism-mud\system\daemons\nature_d.c
 * @Description: 天气守护进程，继承自mudcore
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>

inherit CORE_NATURE_D;

object *outdoor_users()
{
    object *u=({}),env;
    object *users = users();
    foreach(object user in users)
    {
        env = environment(user);
        if(  !inherits(CORE_STD_ROOM,env) )
            continue;
        if( env->query("outdoors") )
            u += ({user});
    }
    return u;
}

void update_day_phase()
{
    string msg;

    msg = ansi(day_phase[current_day_phase]["outcolor"] + day_phase[current_day_phase]["time_msg"] + NOR);
    message("outdoor", msg, outdoor_users());
    if (!undefinedp(day_phase[current_day_phase]["event_fun"]))
        event(this_object(), day_phase[current_day_phase]["event_fun"]);
}
