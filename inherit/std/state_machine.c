/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 17:27:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-29 17:48:13
 * @FilePath: \mysticism-mud\inherit\std\state_machine.c
 * @Description:状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object state,err;
nosave protected object *state_list;

//转换状态至num
void do_switch_state(int num)
{
    foreach(object ob in state_list)
    {
        if(ob->is_state(num)){
            state = ob;
            state->enter_state_do(this_object());
            return;
            }
    }
    err->invalid_state(this_object(),num);
}


void state_init(object obs, int num, object error)
{
    state_list = obs;
    err = error;
    do_switch_state(num);
}
