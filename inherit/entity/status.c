/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-27 15:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-24 17:00:08
 * @FilePath: \mysticism-mud\inherit\entity\status.c
 * @Description: 状态实现基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";

#include <ansi.h>


//状态名称
string status_name(){return "";}
//状态short 介绍
string status_short(){return "";}
//状态id
int status_id(){return 50;}

string print_status_name(object user){return print_mxp_name(3,user);}

int entity_id(){return status_id();}
string mxp_name(){return status_name();}
string mxp_explain(){return status_short();}
string status_description(){return "该状态的详细介绍";}
string entity_description(){return status_description();}
