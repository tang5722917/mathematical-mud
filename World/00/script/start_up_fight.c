/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 18:58:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 16:15:17
 * @FilePath: \mysticism-mud\World\00\script\start_up_fight.c
 * @Description: 新手引导的战斗流程对象
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit CORE_STD_SCRIPT;
#include <game_world.h> 
 combat_event_init(object o1,object o2)
 {
    object mys;
    mys = find_object(PATH_00_MYH "mystic_init_help");
    o1->add_mystic(mys);
    o1->update_mystic();
 }
 combat_event_default(object o1,object o2)
 {
 }

 combat_event_end(object o1,object o2)
 {
    object mys;
    mys = find_object(PATH_00_MYH "mystic_init_help");    
    o1->delete_mystic(mys);
    o1->update_mystic();
 }
