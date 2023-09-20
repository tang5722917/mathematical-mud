/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-09-19 08:00:09
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-20 18:51:55
 * @FilePath: \mysticism-mud\inherit\living\user_machine.c
 * @Description:  实现USER类中对状态机的支持
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

//状态切换
mixed state_change(mapping m,string machine, object state, object event )
{
    object next_ob = state->next_state(event);
    if(!objectp(next_ob))
        return "状态机输入事件无效";
    m[machine] = file_name(next_ob);
    //每次状态转化，对user类进行保存
    this_object()->save();
    return 1;
}
