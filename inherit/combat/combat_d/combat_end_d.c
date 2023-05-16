/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-16 15:58:58
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 19:26:53
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\combat_end_d.c
 * @Description: 处理战斗结束后事宜
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

combat_end_act(combat)
{
    object result_ob;
    result_ob = combat->get_combat_result_ob();
    combat->end_event(result_ob);
}
