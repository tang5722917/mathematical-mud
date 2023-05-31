/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-05 12:32:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-31 19:11:11
 * @FilePath: \mysticism-mud\cmds\wizard\test.c
 * @Description: 用于临时测试
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h> 

inherit CORE_CLEAN_UP;

int help(object me);

mixed *query_localtime()
{
    return TIME_D->query_game_time();
}

int main(object me, string arg)
{
    string str;
    str = load_object(_BOARD)->board_print("从北京华虹NEC，历经一系列变迁，到现在，在公司工作了二十几年，\n这些年，与大家一起开发产品，一起加班，一起旅游，一起在忘年会上表演节目，一起吃饭喝酒，一起讨论大家的活动计划，
作为工会成员，一起分享大家结婚生子的幸福和欢乐，也一起分担失去亲人的忧伤与痛苦，等等等等，
如果上面这些有的同事还不曾与我一起经历，那么至少近两年多来，每月一次操办大家的生日庆祝活动，一起唱过生日歌。",20);
    write(str);
    //add_info("朦胧之中好像听见有人叫你的名字",user);
    //add_info("此时你回想起一些东西",user);
    //if(result_ob->get_result()== 1)
    //    user->move(First_ROOM);
    /*
    //测试出牌序列依据speed排序
    object ob;
    P_CARD p;
    write("sprintf("%O",file);
    write("测试开始\n");
    ob = new(CORE_STD_FIGHT_S);
    ob->add_put_card(load_object(MYSTIC_CARD "01/air_attack"),me,2);
    ob->add_put_card(load_object(MYSTIC_CARD "01/paper_replace"),me,11);
    ob->add_put_card(load_object(MYSTIC_CARD "01/air_attack"),me,4);
    ob->add_put_card(load_object(MYSTIC_CARD "01/paper_replace"),me,13);
    ob->add_put_card(load_object(MYSTIC_CARD "01/paper_replace"),me,4);
    ob->sort_put_card_queue();
    while(p = ob->get_put_card())
        write(p->card->print_card_name(me) +"speed:"+p->speed+"\n");
    */

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
