// efun all_inventory
#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    object env = environment()
    if (!wizardp(me))
        return 0;

    if (!arg)
    {
        printf("%O\n", all_inventory(env));
    }
    else if (ob = load_object(arg))
    {
        print_r(all_inventory(ob));
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@TEXT
指令格式: all_inventory [id]
指令说明:
    列出指定对象环境中的所有对象。
TEXT
    );
    return 1;
}
