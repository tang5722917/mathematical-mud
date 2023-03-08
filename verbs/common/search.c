#include <ansi.h>
inherit _VERB;
inherit PATH_DIR "verbs/inherit/obj_func";

protected void create()
{
    verb::create();
    setVerb("search");
    setSynonyms("sh");
    setRules("", "STR", "OBJ",  "OBJ by OBJ", "OBJ by STR");
    setErrorMessage("你想调查什么?");
}


mixed do_search()
{
    //object me = this_player();
    write("你想调查什么\n");
    return 1;
}

mixed can_search()
{
    if (!environment(this_player()))
        return "没有调查的对象\n";
    else
        return 1;
}


mixed do_search_str(string str)
{
    object ob;
    object me = this_player();
    object env = environment(me);
    ob = object_search_env(str,env);
    if (ob != 0)
    {
        msg("MAG", "$ME开始调查"+ob->short(), me,ob);
        ob->search(me,env);
        return 1;
    }
    return 0;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_search();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_search();
}

mixed direct_search_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}



mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_search();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_search();
}


mixed do_search_obj(object ob)
{
    if(userp(ob))
    {
        object me = this_player() ;
        write("你开始调查"+me->honor_name(me,ob));
        message("info", me->honor_name(me,me)+"调查了你" ,ob);
        return 1;
    }
    return 0;
}


int help(object me)
{
    write(@HELP
指令格式 : ask

这是search指令，可以详细的调查NPC或玩家。
search 能力与自身的灵性相关。灵性越强，越能看到神秘。
但search 有时候会带来意想不到的危险，请谨慎调查。
HELP );
    return 1;
}