#include <ansi.h>
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
    object env = environment(me), obj;
    string * s;
    if (!wizardp(me))
        return 0;

    if (!file)
        return help(me);

    if (file == "here")
    {
        file = base_name(env);
    }
    obj = find_object(file);
    if(obj == 0)
        return 0;
    s = deep_inherit_list(obj);
    write(file+"的继承对象有"+sizeof(s)+"个\n");
    foreach(string str in s)
    {
        write(str+"\n");
    }
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: inherits <对象文件名>
指令说明:
    这个指令用来查看一个对象的继承列表。
HELP );
        return 1;
}
