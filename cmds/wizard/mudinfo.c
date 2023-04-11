#include <ansi.h>
inherit CORE_CLEAN_UP;

#define SCALE   (1.0/10.0)
string duration()
{
    int t, d, h, m, s;
    string time;

    t = uptime();
    s = t % 60;
    t /= 60;
    m = t % 60;
    t /= 60;
    h = t % 24;
    t /= 24;
    d = t;

    if (d)
        time = d + "天";
    else
        time = "";

    if (h)
        time += h + "小时";
    if (m)
        time += m + "分";
    time += s + "秒";

    return time;
}

int main(object me, string arg)
{
    float value;
    string msg;
    mapping r;
    r = rusage();
    value = SCALE * (r["utime"] + r["stime"]) / uptime();
    if (arg == "-v")
    {
        write(NOR + WHT "\n\t\t         .__________ 系 统 资 讯 __________.\n");
        write("\nMUD 名称：" + MUD_NAME + "\n");
        write("驱动环境：" + __ARCH__ + "\n");
        write("驱动版本：" + __VERSION__ + "\n");
        write("pcre库版本：" + pcre_version() + "\n");
        printf("CPU 使用占比：  %f %% 被这个 Mud 使用中\n", value);
        write("执行效率：" + query_load_average() + "\n");
        write("内存占用：" + memory_info() / 1024 / 1024 + "M\n");
        write("运行时间：" + duration() + "\n");
        write("注册用户：" + sizeof(get_dir(DATA_DIR "user/*.o")) + "人\n");
        write("在线玩家：" + sizeof(users()) + "人\n");
        write("游戏生物：" + sizeof(livings()) + "位\n");
        write("载入对象：" + sizeof(objects()) + "个\n");
    }
    else
    {
        msg = WHT BBLU "\n Mud名称       运行时间                           游戏地址                         端口   在线人数" NOR;
        msg += "\n-------------------------------------------------------------\n";
        msg += sprintf(" %-14s%-18s%-50s%-10d%-5d" NOR, MUD_NAME, duration(), "https://gitee.com/mysticism-mud-org/mysticism-mud", __PORT__, sizeof(users()));
        msg += "\n-------------------------------------------------------------\n";
        msg += " " + TIME_D->real_time_description() + "\n";
        msg += " 游戏日历：" + TIME_D->game_time_description() + "\n";
        write(msg);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : mudinfo [-v]

这个指令可以让你查看游戏基本运行信息。

HELP );
    return 1;
}
