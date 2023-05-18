/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-11 19:12:19
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-18 09:23:00
 * @FilePath: \mysticism-mud\inherit\system\command.c
 * @Description: 玩家输入指令处理
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <user.h>
inherit  CORE_COMMAND;

mixed process_input(string arg)
{
    object me,env,ob;
    string arg_l;
    mixed *s_pcre;
    me = this_player();
    env = environment();
#ifdef DEBUG_MYSTICISM
    debug_message("[" + ctime() + "]["+ me->parse_command_id_list()[0] + "]:" +arg);
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
    //指令第一个空格之前部分
    s_pcre = pcre_match_all(arg,"[0-9a-z]+"); 
    arg_l = s_pcre[0][0];
    ob = load_object(USER_IN_NUM);
    if(!me->is_fight_user())
    {
        switch(arg_l)
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
                if(me->is_choice_command()) {
                    if(ob->user_input_number(me,env,to_int(arg)));
                        return 1;
                }
                write("输入的数字没有特别的含义。\n ");
                return 1;
                break;
            case "update":
                break;
            case "y":
            case "Y":
                if(ob->user_choice_confirm(me,env))
                    return 1;
                else {  
                    write("没有什么需要确认\n ");
                    return 1;
                    }
            default:
                if(me->is_choice_command()){
                    write("请输入选项数字。\n ");
                    return 1;
                }
                break;
        }
    return COMMAND_D->default_alias(arg);
    }
    else {
        switch(arg_l)
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
                if(me->is_choice_command()) {
                    if(ob->user_input_number(me,env,to_int(arg)));
                        return 1;
                }
                write("输入的数字没有特别的含义。\n ");
                return 1;
                break;
            case "update":
                break;
            case "y":
            case "Y":
                if(ob->user_choice_confirm(me,env))
                    return 1;
                else {  
                    write("没有什么需要确认\n ");
                    return 1;
                    }
            case "know":
            case "k":
            case "bag":
            case "b":
            case "put":
            case "p":
            case "quit":
            case "q":
                break;
            default:
                write(RED"战斗当中不支持该命令"+arg+"\n " NOR);
                return 1;
        }
        return COMMAND_D->default_alias(arg);
    }

}
