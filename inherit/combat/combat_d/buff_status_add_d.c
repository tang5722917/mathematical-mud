/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-09 10:16:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 10:19:36
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\buff_status_add_d.c
 * @Description: 处理卡牌buff/debuff 新增/初始化事件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 string buff_add(object *user,object card_ob,object combat)
 {
     return card_ob->card_effect_descript();
 }
