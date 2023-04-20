/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-20 19:08:09
 * @FilePath: \mysticism-mud\inherit\skill\skill.c
 * @Description: 技能基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 inherit CORE_STD_TEST;
 inherit _MXP;
 inherit _NAME;
 inherit _MOVE;
 inherit _MESSAGE;
 
 /*开头数字代表类型
 *9  继承自property特殊物品
 *1  Card
 *2  Equit
 *3  Summon
 *4  Skill
 */
 int entity_id(){return 0;}

//技能名称
string skill_name(){return "技能";}
//技能short 介绍
string skill_explain(){return "玩家的一项技能，用于在战斗中生成卡牌/状态，或非战斗时生产/生活";}
//技能d
int skill_id(){return 40;}

int entity_id(){return skill_id();}
string mxp_name(){return skill_name();}
string mxp_explain(){return skill_explain();}
