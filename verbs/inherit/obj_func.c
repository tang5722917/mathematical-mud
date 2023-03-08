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
        if (str == (ob->query("id")))
            if (ob->is_visible())
                return ob;
            if(me->query_status(file_name(ob)) & 1 == 1)
                return ob;
            if(me->temp_query_status(file_name(ob)) & 1 == 1)
                return ob;
    }
    return 0;
}