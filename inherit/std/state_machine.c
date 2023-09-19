/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 17:27:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-16 20:19:07
 * @FilePath: \mysticism-mud\inherit\std\state_machine.c
 * @Description:状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object err;
nosave protected object state_list;

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

int add_state(object state)
{
    if(!inherits(_STATE,state))
        return 0;
    state_list->add_list_ob(state)
}


varargs void state_machine_init(string machine_name,string machine_id,string brief)
{
    state_list = new(_LIST);
    state_list->init(_STATE_M);

    if(stringp(machine_name))
        state_list->set_list_prop("name",machine_name);
    else 
        state_list->set_list_prop("name","state_machine");
    if(stringp(machine_id))
        state_list->set_list_prop("id",machine_id);
    else state_list->set_list_prop("id","");
    if(stringp(brief))
        state_list->set_list_prop("brief",brief);
    else state_list->set_list_prop("brief","");
    
    err = new(_ERR);
}
