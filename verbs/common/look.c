#include <ansi.h>

inherit CORE_DIR "verbs/common/look";
inherit PATH_DIR "verbs/inherit/obj_func";

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
        ob->look(me);
        return 1;
    }
        
    cecho("这里没有你想看的呢。");

    return 0;
}
