/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-13 13:53:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-17 14:40:01
 * @FilePath: \mysticism-mud\verbs\common\quit.c
 * @Description:  quit(q) 指令
 *               退出战斗或某些场景
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
 
 //#include <ansi.h> 
 inherit _VERB;
 inherit PATH_DIR "verbs/inherit/obj_func";
#include <ansi.h>
 
 protected void create()
 {
     verb::create();
     setVerb("quit");
     setSynonyms("q");
     setRules("", "STR");
     setErrorMessage("没有什么能退出的");
 }

 mixed do_quit()
{
    object me = this_player();
    object ob;
    if(me->fight_object() != 0)
    {
        ob=me->fight_object()->combat_object();
        if (me->is_fight_user())
        {
            if(ob->is_quit_fight() != 0)
            {
                me->fight_object()->combat_end();
                me->end_fight();
            }
            else
            {
                write("无法逃离敌人!\n");
            }
        }
        else write("你想从哪里退出?\n");
    }
    else 
        write("没有需要退出地场景！\n");

    return 1;
}

mixed can_quit()
{
    if(! this_player()->is_fight_user())
        return "目前不在战斗当中\n";
    else
        return 1;
}

mixed do_quit_str(string str)
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
    return can_quit();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_quit();
}

mixed direct_quit_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}



mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_quit();
}

 int help(object me)
{
    write(@HELP
指令格式 : quit（q） 

这是quit指令，可以从战斗或某些情景退出（如果允许玩家退出）。
HELP );
    return 1;
}