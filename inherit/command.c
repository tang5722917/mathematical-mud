
#include <ansi.h>
inherit  CORE_COMMAND;

string process_input(string arg)
{
    object me;
    me = this_player();
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
        write(RED"战斗当中不支持该命令"+arg+"\n " NOR);
        return 0;
    }

}