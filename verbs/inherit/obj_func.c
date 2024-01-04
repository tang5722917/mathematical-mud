/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-04 18:14:45
 * @FilePath: \mysticism-mud\verbs\inherit\obj_func.c
 * @Description: 
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>

object object_search_env(string str,object env)
{
    object *inv;
    object *obs;
    object me=this_player();
    inv = all_inventory(env);
    if (!sizeof(inv))
        return 0;

    obs = filter_array(inv, (: $(me) != $1 :));
    if (!sizeof(obs))
        return 0;    

    foreach (object ob in obs)
    {
        if ((str == (ob->query("id"))) || (str == (ob->id_look())) ){
            if (ob->is_visible())
                return ob;
            if(ob->env_display())
                return ob;
            if(me->query_status(file_name(ob)) & 1 == 1)
                return ob;
            if(me->temp_query_status(file_name(ob)) & 1 == 1)
                return ob;
        }
    }
    return 0;
}
