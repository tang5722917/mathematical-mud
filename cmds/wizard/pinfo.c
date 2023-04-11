#include <ansi.h>
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
    object env = environment(me), obj;
    string s;
    mapping m;
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
    m = program_info(obj);

    s = sprintf("
    对象名：%s
    header size : %d
    code size : %d
    function size : %d
    var size : %d
    class size : %d
    inherit size : %d
    saved type size : %d
    total size : %d",file,m["header size"],
    m["code size"],m["function size"],m["var size"],m["class size"],
    m["inherit size"],m["saved type size"],m["total size"]);
    write(s);
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: pinfo <对象文件名>
指令说明:
    这个指令用来查看一个对象的资源消耗。
HELP );
        return 1;
}
