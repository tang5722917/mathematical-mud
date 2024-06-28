/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 17:27:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-05-29 18:45:39
 * @FilePath: \mysticism-mud\inherit\std\state_machine.c
 * @Description:状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object err;
nosave protected mapping machine_data;
nosave protected object state;
//将状态类载入状态机
int machine_init(mixed * state_list){
    machine_data = ([]);
    machine_data["trigger"] = ({});  //trigger list
    machine_data["State"] = ([]);    //state list
    if(!arrayp(state_list) && (sizeof(state_list) > 0))
        return 0;
    foreach (object stat in state_list){
        if(!objectp(stat)) return -1;
        machine_data["State"][stat->state_name()] = stat;
    }
    //默认state_list[0]为当前状态
    state = state_list[0];
    return 1;
}
//设置Trigger与状态转换
int machine_build(mixed * machine){
    if(!arrayp(machine) || (sizeof(machine) < 0))
        return 0;
    foreach (mapping mach in machine)
    {
        // 定义trigger 函数
        if(!mapp(mach)) return -1;
        if(!stringp(mach["trigger"])) return -2;
        //定义原状态
        if(!stringp(mach["source"])) return -3;
        if(!objectp(machine_data["State"][mach["source"]])) return -4;
        //定义目标状态
        if(!stringp(mach["dest"])) return -5;
        if(!objectp(machine_data["State"][mach["dest"]])) return -6;

        machine_data["trigger"] += ({mach});
    }
    return 1;
}

//设置当前状态
int set_current_state_name(string name){
    object ob;
    if(!stringp(name)) return 0;
    ob = machine_data["State"][name];
    if(!objectp(ob)) return 0;
    state = ob;
    return 1;
}

//得到当前状态
object get_current_state(){
    return state;
}

//得到状态数量
int get_size_state(){return sizeof(machine_data["State"]);}

//转换状态至状态名
int do_switch_state_name(string name)
{
    object ob;
    if(!stringp(name)) return 0;
    state->typ_exit(this_object());
    ob = machine_data["State"][name];
    if(!objectp(ob)) return 0;
    state = ob;
    state->typ_enter(this_object());
    return 1;
}

int add_state(object state)
{

}


varargs void state_machine_init(string machine_name,string machine_id,string brief)
{

}

//使用 trigger name 来触发
mixed trigger(string str){
    if(!stringp(str)) return -1;
    foreach (mapping trig in machine_data["trigger"])
    {
        if(trig["trigger"] == str){
            if(state->is_state(trig["source"])){
                if(do_switch_state_name(trig["dest"]))
                {
                    if(function_exists(str))
                        return call_other(this_object(),str);
                    else return 1;
                }
                else return -1; 
            }
        }
    }
    return 0;
}

//自定义状态变量
mixed set(string prop, mixed data){
    return machine_data[prop] = data;
}
mixed query(string prop){
    return machine_data[prop];
}
