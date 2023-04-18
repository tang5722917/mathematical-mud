/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-07 19:14:15
 * @FilePath: \mysticism-mud\inherit\entity\summon.c
 * @Description: 召唤物基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";
inherit _DBASE;


//召唤物名称
string summon_name(){return "召唤物";}
//召唤物short 介绍
string summon_explain(){return "出现于战场之上，协助主人战胜对手";}

string mxp_name(){return summon_name();}
string mxp_explain(){return summon_explain();}
