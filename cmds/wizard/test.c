/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-05 13:17:29
 * @FilePath: \mysticism-mud\cmds\wizard\test.c
 * @Description: 用于临时测试
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <combat.h> 
#include <game_world.h> 
inherit CORE_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
    //测试出牌序列依据speed排序
    object ob;
    P_CARD p;
    write("测试开始\n");
    ob = new(CORE_STD_FIGHT_S);
    ob->add_put_card(load_object(MYSTIC_CARD "01/air_attack"),me,3);
    ob->add_put_card(load_object(MYSTIC_CARD "01/paper_replace"),me,11);
    ob->add_put_card(load_object(MYSTIC_CARD "01/air_attack"),me,3);
    ob->add_put_card(load_object(MYSTIC_CARD "01/paper_replace"),me,13);
    ob->sort_put_card_query();
    while(p = ob->get_put_card())
        write(p->card->print_card_name(me));
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式: test
用于临时测试
HELP );
        return 1;
}
