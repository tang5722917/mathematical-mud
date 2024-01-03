/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-03 17:32:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-03 19:15:53
 * @FilePath: \mysticism-mud\inherit\entity\common.c
 * @Description: 公共物品基类
 * Copyright (c) 2024 by error: git config user.name & please set dead value or install git email: error: git config user.email & please set dead value or install git, All Rights Reserved.
 */

#include <ansi.h>

inherit INHERIT_PATH "entity/entity";

string common_name(){return "公共物品";}
string common_short(){return "用于当作道具的公共物品";}
int common_id(){return 80;}

int entity_id(){return common_id();}
string mxp_name(){return common_name();}
string mxp_explain(){return common_short();}
string print_mxp_other(object user){return print_mxp_name(10,user);}
