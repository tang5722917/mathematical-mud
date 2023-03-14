#include <ansi.h>
inherit _VERB;
inherit PATH_DIR "verbs/inherit/obj_func";

protected void create()
{
    verb::create();
    setVerb("fight");
    setSynonyms("f");
    setRules("", "STR", "OBJ",  "OBJ by OBJ", "OBJ by STR");
    setErrorMessage("你想和谁战斗?");
}


mixed do_fight()
{
    //object me = this_player();
    write("你想要攻击谁？\n");
    return 1;
}

mixed can_fight()
{
    if (!environment(this_player()))
        return "没有询问的对象\n";
    if(this_player()->is_fight_user())
        return "已经在战斗当中\n";
    else
        return 1;
}


mixed do_fight_str(string str)
{
    object ob, fob;
    object *ob1,*ob2;
    object me = this_player();
    object env = environment(me);
    ob = object_search_env(str,env);
    if (ob != 0)
    {
        write("你向"+ob->honor_name(me,ob)+"发动攻击\n");
        ob2 = ob->fight(me,ob);
        ob1 = me->fight(me,ob);
        fob = new(FIGHT_D,ob1,ob2,0,env);
        me->into_cur_fight(fob);
        return 1;
    }
    return 0;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_fight();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_fight();
}

mixed direct_fight_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}



mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_fight();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_fight();
}


mixed do_fight_obj(object ob)
{
    if(userp(ob))
    {
        object me = this_player() ;
        write("你向"+ob->honor_name(me,ob)+"发起挑战\n");
        message("info", me->honor_name(me,me)+"向你发起挑战" ,ob);
        write("要和平相处，不要打架！\n");
        message("info", "要和平相处，不要打架！" ,ob);
        return 1;
    }
    return 0;
}


int help(object me)
{
    write(@HELP
指令格式 : fight (f) + 玩家/NPC ID
这是fight指令，可以向NPC或玩家发起战斗。
HELP );
    return 1;
}