#include <ansi.h>

inherit CORE_DIR "verbs/common/look";
inherit PATH_DIR "verbs/inherit/obj_func";

int show_look(int arg,object me,object ob)
{
    //string str;
    if(ob == me)
        return 0;
    if(userp(ob))
        return 1;
    if(me->query_status(ob->query("id")) & 1 == 1)
        return 1;
    if(me->temp_query_status(file_name(ob)) & 1 == 1)
        return 1;
    if (ob->is_visible() == 0)
        return 0;
    else return 1;
}

string is_fight(object ob)
{
    object me;
    me = this_player();
    write("数据"+me->temp_query_status(file_name(ob))+"\n");
    if(ob->is_fight_living())
        return RED"->该目标有攻击性，请小心" NOR;
    if(me->query_status(ob->query("id")) == 3)
        return RED"->该目标有攻击性，请小心" NOR;
    if(me->temp_query_status(file_name(ob)) == 3){
        return RED"->该目标有攻击性，请小心" NOR;}
    else return "";
}

string desc_of_objects(object *obs)
{
    int i;
    string str;
    mapping list, unit;
    string short_name;
    string *ob;

    if (obs && sizeof(obs) > 0)
    {
        str = "";
        list = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            short_name = obs[i]->short() + is_fight(obs[i]) ;

            list[short_name] += obs[i]->query_temp("amount") ? obs[i]->query_temp("amount") : 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(ob); i++)
        {
            str += "  ";
            if (list[ob[i]] > 1)
                str += list[ob[i]] + unit[ob[i]] + ob[i]+ "\n";
            else
                str += ob[i]+ "\n";
        }
        return str;
    }

    return "";
}

string list_all_inventory_of_object(object me, object env)
{
    object *inv;
    object *obs;
    string str = "";

    if (!env || !me)
        return "";

    inv = all_inventory(env);
    if (!sizeof(inv))
        return str;

    obs = filter_array(inv, (:show_look,env->get_room_type(),me:));
    str += desc_of_objects(obs);

    return str;
}



int look_room(object me, object env)
{
    string str, *dirs;
    mapping exits;

    if (env->is_area())
    {
        return env->do_look(me);
    }

    str = sprintf(HIC + "%s" + NOR + "%s\n    %s" + NOR,
                  env->short(), wizardp(me) ? " - " + env : env->Room_name(),
                  sort_string(env->long(), 72, 4));
    // env->long());

    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);

        if (sizeof(dirs) == 0)
            str += "    这里没有任何明显的出路。\n";
        else if (sizeof(dirs) == 1)
            str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else
            str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                           implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs) - 1]);
    }
    else
    {
        str += "    这里没有任何出路。\n";
    }
    str += list_all_inventory_of_object(me, env);
    tell_object(me, str);
    return 1;
}

    //  查看NPC/玩家
mixed do_look_at_str(string str, string arg)
{
    object ob;
    object me = this_player();
    object env = environment(me);
    mapping exits = env->query("exits");
    string tar = list_all_inventory_of_object(me, env);
    tell_object(me, tar);
    if (str == "here")
    {
        return do_look();
    }
    // 查看出口方向
    if (mapp(exits))
    {
        if (stringp(exits[str]))
            return look_room(me, load_object(exits[str]));
        else if (mapp(exits[str]))
        {
            cecho("此方向是区域环境，无法观察。");
            return 0;
        }
    }
    if (env->is_area())
        return env->do_look(me, str);
//查看NPC
    ob = object_search_env(str,env);
    if (ob != 0)
    {
        do_look_at_obj(ob);
        ob->look(me,env);
        return 1;
    }
// 只有该玩家可以看到的NPC/物品/出口

    cecho("这里没有你想看的呢。");

    return 0;
}
