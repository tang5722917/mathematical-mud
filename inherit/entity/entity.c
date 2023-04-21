/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 19:29:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-21 15:03:55
 * @FilePath: \mysticism-mud\inherit\entity\entity.c
 * @Description:  物品基类
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
*5  Status
*/
int entity_id(){return 0;}
