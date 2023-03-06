
inherit CORE_DIR "verbs/common/go";

int do_go_str(string dir, string arg)
{
    object me = this_player();
    object env = environment(me);
    if(me->is_fight_user() == 1 )
    {
        write("你正在战斗当中，无法移动 \n");
        return 0;
    }
    if (env->is_area())
        return do_area_move(me, env, arg);
    else
        return do_room_move(me, env, arg);
}