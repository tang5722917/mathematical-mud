
inherit  CORE_COMMAND;

string process_input(string arg)
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