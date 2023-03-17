/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-21 18:09:47
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-02-21 18:30:58
 * @FilePath: \mysticism-mud\inherit\mystic.c
 * @Description:  非凡能力基础类
 * 
 * Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved. 
 */

int affect_hp(object LIVING) {return LIVING->query_base_hp();}
int affect_mp(object LIVING) {return LIVING->query_base_mp();}
int affect_int(object LIVING) {return LIVING->query_base_int();}
int affect_cra(object LIVING) {return LIVING->query_base_cra();}
int affect_luk(object LIVING) {return LIVING->query_base_luk();}
int affect_str(object LIVING) {return LIVING->query_base_str();}
int affect_agi(object LIVING) {return LIVING->query_base_agi();}

