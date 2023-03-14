/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-27 18:17:18
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-14 17:32:27
 * @FilePath: \mysticism-mud\cmds\player\know.c
 * @Description:  游戏中的知识界面
 *                包括冒险帮助与冒险经历
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;
#include <ansi.h>
#include <game_world.h>


object find_know(string verb)
{
    object file;
/*
    string *path = KNOW_PATH;
    mapping current;

    if (this_player() && wizardp(this_player()))
    {
        path += KNOW_PATH_WIZ;
    }

    foreach(string p in path)
    {
        if (undefinedp(current = commands[p]))
        {
            rehash();
            if (undefinedp(current = commands[p]))
                continue;
        }
        if (stringp(current[verb]) && objectp(file = load_object(current[verb])))
        {
            return file;
        }
    }
*/
    return 0;
}

int help(object me)
{
    write(@KNOW
指令格式 : know [数字]
这个指令可以查看指定数字主题的的详细内容。
包括基本冒险帮助信息以及玩家的冒险经历。
其中的有些内容将随着游戏的剧情而增加。
KNOW );
    return 1;
}


int main(object me, int arg )
{
    object file;
    write(BYEL"                  诡秘见闻录                   \n" NOR);
    write(WHT"                 version:"Know_how_version"               \n" NOR);
    if(arg)
    {
        if( objectp(file = COMMAND_D->find_know(arg)) ) {
            // notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
            return file->know(me);
        }
        if( objectp(file = COMMAND_D->find_know(arg)) ) {
            // notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
            return file->know(me);
        }
    }

    return help(me);
}