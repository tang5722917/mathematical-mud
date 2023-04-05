#include <ansi.h>
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
    object env = environment(me), obj;
    string * ob,s;
    if (!wizardp(me))
        return 0;

    if (!file)
        return help(me);

    if (file == "here")
    {
        file = base_name(env);
    }
    if (file == VOID_OB)
        return notify_fail(HIR "你不能在 VOID_OB 里重新编译 VOID_OB。\n" NOR);

    write("重新编译[" + file + "]:");
    obj = find_object(file);
    if (obj == 0)
        cecho("错误的文件名");
    else
    {
        ob = deep_inherit_list(obj);
        if(sizeof(ob)!=0)
            foreach(s in ob)
            {
                destruct(find_object(s));
            }
        destruct(obj);
    }
    if(sizeof(ob)!=0)
        foreach(s in ob)
        {
            load_object(s);
        }    
    if (objectp(load_object(file)))
    {
        cecho("编译成功!");
    }
    else
    {
        cecho("失败，文件不存在!");
    }

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: update <对象文件名>
指令说明:
    这个指令用来重新载入一个对象。
HELP );
        return 1;
}
