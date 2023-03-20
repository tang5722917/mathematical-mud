/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-20 18:10:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-20 19:03:55
 * @FilePath: \mysticism-mud\inherit\mystic\mystic_value.c
 * @Description: 处理非凡特性对数值的影响
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

 vodi change_value(object living)
 {
    
 }

 int affect_hp(object LIVING) {return LIVING->query_base_hp();}
 int affect_mp(object LIVING) {return LIVING->query_base_mp();}
 int affect_int(object LIVING) {return LIVING->query_base_int();}
 int affect_cra(object LIVING) {return LIVING->query_base_cra();}
 int affect_luk(object LIVING) {return LIVING->query_base_luk();}
 int affect_str(object LIVING) {return LIVING->query_base_str();}
 int affect_agi(object LIVING) {return LIVING->query_base_agi();}
