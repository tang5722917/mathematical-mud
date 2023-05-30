/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-30 16:15:55
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-30 16:16:06
 * @FilePath: \mysticism-mud\cmds\player\pop.c
 * @Description: 查看阵营声望命令
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    object ob = load_object(MAP_SHOW_D);
    write( ob->show_map(me));
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: pop
显示游戏玩家阵营的声望信息
HELP );
        return 1;
}
