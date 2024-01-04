/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-09 20:07:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-10 14:40:17
 * @FilePath: \mysticism-mud\inherit\entity\materials.c
 * @Description: 无非凡特性实体基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit INHERIT_PATH "entity/entity";
inherit INHERIT_PATH "entity/space_entity";

//物品名称
string materials_name(){return "实体";}
//物品short 介绍
string materials_explain(){return "没有非凡特性的普通物品";}
//物品id
int materials_id(){return 60;}
string print_materials_name(object user){return print_mxp_name(10,user);}
int entity_id(){return materials_id();}
string mxp_name(){return materials_name();}
string mxp_explain(){return materials_explain();}

string materials_description(){return "材料的详细用途";}
string entity_description(){return materials_description();}
