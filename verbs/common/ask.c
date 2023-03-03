#include <ansi.h>
inherit _VERB;
inherit "/verbs/inherit/obj_func";

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
    object me = this_player();
    object env = environment(me);
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

mixed can_ask_at_obj(object ob)
{
    if (!environment(this_player()))
        return "没有询问的对象\n";
    else
        return 1;
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
    return 1;
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


mixed do_ask_str(object ob)
{
    ob->answer(ob);
    return 1;
}