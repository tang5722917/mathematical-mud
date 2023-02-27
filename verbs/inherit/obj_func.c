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
            return ob;
    }
    return 0;
}