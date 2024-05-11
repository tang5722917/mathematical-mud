/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 15:37:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-05-11 19:07:06
 * @FilePath: \mysticism-mud\inherit\std\state.c
 * @Description:  有限状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected mapping state_data;
//num  状态编号  str 状态名 * 不可省略
void init(string str){
    state_data = ([]);
    state_data["name"] = str;
    state_data["on_enter"] = 0;  //进入该状态后做的事
    state_data["on_exit"] = 0;   //即将离开某状态时做的事
    state_data["before"] = 0;    //before:属性转换方法 调用开始之前进行回调，此时属性未转变
    state_data["after"] = 0;     //after: 属性转换方法 调用即将结束前进行回调，此时属性已改变
}

int state_build(mapping state)
{
    if(stringp(state["name"]))
        init(state["name"]);
    else return 0;
    if(stringp(state["on_enter"]))
        state_data["on_enter"] = state["on_enter"];
    if(stringp(state["on_exit"]))
        state_data["on_exit"] = state["on_exit"];
    if(stringp(state["before"]))
        state_data["before"] = state["before"];
    if(stringp(state["after"]))
        state_data["after"] = state["after"];    
    return 1;
}

//判断是否是本状态 name
int is_state_name(string str){return (str == state_data["name"]);}
//得到本状态名称
string state_name(){return state_data["name"];}
//得到状态信息
string state_info(){
    string str="";
    str += "State name: " + state_data["name"];
    return str;}
//状态转换：
//`before`属性 -> `on_exit`属性 -> `on_exit_{stateName}`
//`on_enter`属性 -> `on_enter_{stateName}`方法 -> `after`属性

//自定义状态变量
mixed set(string prop, mixed data){
    return state_data[prop] = data;
}
mixed query(string prop){
    return state_data[prop];
}
