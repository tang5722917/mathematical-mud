/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 17:27:16
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-05-11 19:05:26
 * @FilePath: \mysticism-mud\inherit\std\state_machine.c
 * @Description:状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object err;
nosave protected mapping machine_data;
nosave protected object state;
//
void machine_init(){
    machine_data = ([]);
    machine_data["trigger"] = ({});  //trigger list
    machine_data["State"] = ([]);    //state list
    state = 0
}

int machine_build(mixed * machine){
    machine_init()
    if(!arrayp(machine) && (sizeof(machine) > 0))
        return 0;
    foreach (mapping mach in machine)
    {
        // 定义trigger 函数
        if(!mapp(mach)) return -1;
        if(!stringp(mach["trigger"])) return -2;
        //定义原状态
        if(!stringp(mach["sourcer"])) return -3;
        if(objectp(machine_data["State"][mach["sourcer"]])) return -4;
        //定义目标状态
        if(!stringp(mach["dest"])) return -5;
        if(objectp(machine_data["State"][mach["dest"]])) return -6;

        machine_data["trigger"] += ({mach})
    }
    return 1;
}

int set_current_state_name(string name){
    machine_data["State"]["name"]
}


//转换状态至num
void do_switch_state(int num)
{

}

int add_state(object state)
{

}


varargs void state_machine_init(string machine_name,string machine_id,string brief)
{

}
//使用 trigger name 来触发
int trigger(string str){

}



//自定义状态变量
mixed set(string prop, mixed data){
    return machine_data[prop] = data;
}
mixed query(string prop){
    return machine_data[prop];
}
