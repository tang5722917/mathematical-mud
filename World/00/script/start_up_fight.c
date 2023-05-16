/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 18:58:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 15:24:16
 * @FilePath: \mysticism-mud\World\00\script\start_up_fight.c
 * @Description: 新手引导的战斗流程对象
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit CORE_STD_SCRIPT;
#include <game_world.h> 
#include <combat.h>
/*本场战斗涉及的对象
*PATH_00_MYH "mystic_init_help"   临时加载在玩家身上的非凡特性
*MYSTIC_CARD "01/air_attack"      空气子弹
*MYSTIC_CARD "01/paper_replace"   纸人替身
*MYSTIC_CARD "12/fire_ball"       火球术
*PATH_00_STA "newbie_status"      出生战斗特殊状态
*paper_replace
*/

 combat_event_init(object f,object o1,object o2)
 {
   //在玩家身上加载非凡特性
    f->add_f_ins("突然感觉体内涌现一股神秘的力量！",o1,MYS,find_object(PATH_00_MYH "mystic_init_help"));
    f->add_f_ent(PATH_00_STA "newbie_status",o1);  //获得出生战斗特殊状态
    f->add_f_ent(MYSTIC_CARD "01/air_attack",o1);     //获得空气子弹牌
    f->add_f_ent(MYSTIC_CARD "01/paper_replace",o1);  //获得纸人替身牌
    f->add_f_ent(MYSTIC_CARD "12/fire_ball",o2);      //对方获得火球术牌
    f->add_f_info("可以通过输入“score/sc”指令查看自身的状态");  
 }

 combat_event_end(object f,object o1,object o2)
 {
     f->add_f_ins("感到身上的力量衰退了",o1,MYS_R,find_object(PATH_00_MYH "mystic_init_help"));
 }


 //combat_process_round_*  代表第*轮发生的事件
 combat_process_round_1(object f,object o1,object o2)
 {

 }

//每一轮摸牌阶段固定发生事件
 combat_event_round_pve_s(object f,object o1,object o2)
 {
   object user_data1 = f-> get_ob_data(o1);
   object user_data2 = f-> get_ob_data(o2);
   f->add_f_ent(user_data2->get_one_card(),o2); 
   f->add_f_ent(user_data1->get_one_card(),o1); 
   f->add_f_ent(user_data1->get_one_card(),o1); 
 }
//每一轮出牌阶段固定发生事件
combat_put_round_pve_s(object f,object o1,object o2)
{
   object user_data2 = f-> get_ob_data(o2);
   foreach(object ob in user_data2->get_card())  //每一回合o2出光所有手牌
      f->put_f_ent(file_name(ob),o2);
   user_data2->remove_card(user_data2->get_card());
}
