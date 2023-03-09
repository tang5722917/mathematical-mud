#include <ansi.h>
inherit _VERB;
inherit PATH_DIR "verbs/inherit/obj_func";

protected void create()
{
    verb::create();
    setVerb("ask");
    setSynonyms("a");
    setRules("", "STR", "OBJ",  "OBJ by OBJ", "OBJ by STR");
    setErrorMessage("你想问什么?");
}


mixed do_ask()
{
    //object me = this_player();
    write("你想问什么\n");
    return 1;
}

mixed can_ask()
{
    if (!environment(this_player()))
        return "没有询问的对象\n";
    else
        return 1;
}


mixed do_ask_str(string str)
{
    object ob;
    object me = this_player();
    object env = environment(me);
    ob = object_search_env(str,env);
    if (ob != 0)
    {
        msg("MAG", "$ME向"+ob->honor_name(me,ob)+"提出疑问。", me,ob);
        ob->answer(me,env);
        return 1;
    }
    return 0;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_ask();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_ask();
}

mixed direct_ask_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}



mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_ask();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_ask();
}


mixed do_ask_obj(object ob)
{
    if(userp(ob))
    {
        object me = this_player() ;
        msg("MAG", "$ME向"+ob->honor_name(me,ob)+"提问。", me,ob);
        return 1;
    }
    return 0;
}

mixed do_ask_obj_by_str(object ob,string str)
{
    object me = this_player() ;
    write("你向"+me->honor_name(me,ob)+"问到：" + str);
    message("info", me->honor_name(me,me)+"向你问到：" + str ,ob);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : ask（a） + 玩家/NPC ID
           ask（a） + 玩家/NPC ID by 内容（字符串）
ask指令可以向NPC或玩家提问。
HELP );
    return 1;
}