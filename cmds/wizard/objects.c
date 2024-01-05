// 打印所有载入游戏的对象
inherit _CLEAN_UP;

int main(object me, string arg)
{
    if (!wizardp(me))
        return 0;

    if (arg == "-c")
        print_r(objects( (:clonep:) ));
    else if (arg == "-o")
        print_r(objects( (: !clonep($1) :) ));
    else if (arg == "-v")
    {
        print_r(objects( (:virtualp:) ));
    }
    else if (arg == "-u")
    {
        print_r(objects( (:userp:) ));
    }
    else if (arg == "-a")
    {
        print_r(objects());
    }
    else if (arg == "-x")
    {
        write("  对象数据统计："+"\n");
        write("复制对象数：" +sizeof(objects( (:clonep:) ))+"\n");
        write("蓝图对象数：" +sizeof(objects((: !clonep($1) :)))+"\n");
        write("虚拟对象数：" +sizeof(objects((:virtualp:)))+"\n");
        write("用户对象数：" +sizeof(objects((:userp:)))+"\n");
        write("总对象数：  " +sizeof(objects()));
    }
    else
        write("总对象数：" +sizeof(objects()));

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: objects <参数>
指令说明:
    这个指令用来打印游戏中载入的对象列表，参数 -c 为复制对象，参数 -o 为蓝图对象，参数 -v 为虚拟对象。
    -a 打印全部对象
    -u 打印所有user对象
    -x 打印对象数据统计
HELP);
    return 1;
}
