inherit _VERB;
#include <mxp.h> 
#include <ansi.h>

inherit PATH_DIR "verbs/inherit/obj_func";

int look_room(object me, object env);
string desc_of_objects(object *obs);
string list_all_inventory_of_object(object me, object env);
mixed do_look_at_str(string str, string arg);

protected void create()
{
    verb::create();
    setVerb("look");
    setSynonyms("l");
    setRules("", "STR", "OBJ", "at STR", "at OBJ", "on OBJ", "in OBJ", "inside OBJ",
             "at OBJ in OBJ", "OBJ inside OBJ", "at OBJ on OBJ", "at STR on OBJ");
    setErrorMessage("你想看什么?");
}


mixed can_look()
{
    if (!environment(this_player()))
        return "你的四周灰蒙蒙地一片，什么也没有。\n";
    else if (this_player()->is_fight_user())
    {
        return "请专心致志地战斗，不要东张西望！\n";
    }
    else
        return 1;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_look();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_look();
}

mixed direct_look_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}

mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_look();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_look();
}

mixed do_look()
{
    object me = this_player();
    object env = environment(me);

    return look_room(me, env);
}

mixed do_look_str(string str, string arg)
{
    return do_look_at_str(str, arg);
}

mixed do_look_at_obj(object ob)
{
    object me = this_player();

    if (userp(ob))
    {
        msg("info", "$ME认真的看了$YOU一眼。", me, ob);
        printf("%s 是一位 %d 级的%s。\n", ob->short(), ob->query("lv"), ob->query("gender"));
    }
    else
    {
        printf("%s\n", ob->long());
    }

    return 1;
}

mixed do_look_at_obj_in_obj(object ob1, object ob2, string id1, string id2)
{
    printf("%s\n", ob1->long());
    return 1;
}

mixed do_look_obj(object ob)
{
    return do_look_at_obj(ob);
}

mixed do_look_in_obj(object ob)
{
    if (sizeof(all_inventory(ob)))
    {
        cecho(sprintf("%s里有:\n%s", ob->short(), list_all_inventory_of_object(ob, ob)));
    }
    else
    {
        cecho(sprintf("%s里什么也没有。", ob->short()));
    }

    return 1;
}

mixed do_verb_rule(mixed *data...)
{
    debug(data);
    return 1;
}

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
    if( env->query("outdoors") )
        str += load_object(NATURE_D)->outdoor_room_description()+NOR "\n";
    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);

        if (sizeof(dirs) == 0)
            str += "    这里没有任何明显的出路。\n";
        else if (sizeof(dirs) == 1)
            str += "    这里唯一的出口是 " + exits[dirs[0]]->print_mxp_name(MXP_MAP,me,dirs[0]) + "。\n";
        else{
            str += "    这里明显的出口是 ";
            foreach(string k, object ob in exits){
                str += ob->print_mxp_name(MXP_MAP,me,k)+" ";
            }
            str += "\n";
        }
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

int help(object me)
{
    write(@HELP
指令格式 : look + NPC/物品/玩家
这是MUDCORE框架提供的最基本的look指令，可以查看当前环境。
标准环境需要有环境名称(short)、环境描述(long)和环境出口(exits)。
HELP );
    return 1;
}
