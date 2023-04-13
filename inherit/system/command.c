
#include <ansi.h>
inherit  CORE_COMMAND;

mixed process_input(string arg)
{
    object me;
    me = this_player();
#ifdef DEBUG_MYSTICISM
    debug_message("[" + ctime() + "]"+arg+"\n");
#endif
    if(arg[0] == 32)  //MXP 返回信息以数字32开头
    {
        if(strlen(arg) >= 13)
        {
            if(arg[5..11] == "VERSION")
                me->SetMXPVersion(arg[13..strlen(arg)-2]);
            if(arg[5..11] == "SUPPORT")
                me->SetMXPSupportInfo(arg[14..strlen(arg)-2]);
        }
        return 1;
    }
    if(!wizardp(me))
        if(me->user_input())
            return 1;
    if(!me->is_fight_user())
    {
        switch(arg)
        {
            case "0":
            case "1":
            case "2":
            case "3":
            case "4":
            case "5":
            case "6":
            case "7":
            case "8":
            case "9":
                write("输入的数字没有特别的含义。\n ");
                break;
            default:break;
        }
    return COMMAND_D->default_alias(arg);
    }
    else {
        switch(arg)
        {
            case "0":
            case "1":
            case "2":
            case "3":
            case "4":
            case "5":
            case "6":
            case "7":
            case "8":
            case "9":
                write("输入的数字没有特别的含义。\n ");
                break;
            default:break;
        }
        switch(arg)
        {
            case "know":
            case "k":
            case "bag":
            case "b":
                write(RED"战斗当中不支持该命令"+arg+"\n " NOR);
                return 1;
                break;
            default:
        }
        return COMMAND_D->default_alias(arg);
    }

}
