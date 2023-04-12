#include <ansi.h>
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    if (!wizardp(me))
        return 0;
    if (arg == "-v")
    {
        ;
    }
    else
    {
        ;
    }
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: pinfo <对象文件名>
指令说明:
    这个指令用来查看数据库状态信息。
HELP );
        return 1;
}
