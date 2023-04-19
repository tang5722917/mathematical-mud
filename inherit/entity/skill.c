/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-19 17:52:05
 * @FilePath: \mysticism-mud\inherit\entity\summon.c
 * @Description: 召唤物基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";

//技能名称
string skill_name(){return "召唤物";}
//技能short 介绍
string skill_explain(){return "出现于战场之上，协助主人战胜对手";}
//技能d
int skill_id(){return 40;}

int entity_id(){return skill_id();}
string mxp_name(){return skill_name();}
string mxp_explain(){return skill_explain();}
