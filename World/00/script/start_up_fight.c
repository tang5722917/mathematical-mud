/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 18:58:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-18 15:22:15
 * @FilePath: \mysticism-mud\World\00\script\start_up_fight.c
 * @Description: 新手引导的战斗流程对象
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit CORE_STD_SCRIPT;
#include <game_world.h> 
#include <combat.h>


 combat_event_init(object f,object o1,object o2)
 {
    f->add_f_info("突然感觉体内涌现一股神秘的力量！",o1,MYS,find_object(PATH_00_MYH "mystic_init_help"));
 }

 combat_event_end(object f,object o1,object o2)
 {
    f->add_f_info("感到身上的力量衰退了",o1,MYS_R,find_object(PATH_00_MYH "mystic_init_help"));
 }


 //combat_process_round_*  代表第*轮发生的事件
 combat_process_round_1(object f,object ob1,object ob2)
 {
    message("FIG","第一回合出牌",ob1);
 }
