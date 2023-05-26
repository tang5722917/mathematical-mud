/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 11:37:48
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-26 18:55:02
 * @FilePath: \mysticism-mud\inherit\living\user_message.c
 * @Description: 玩家Message 处理
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
//user接受的NPC对话 massage
#include <user.h>

nosave protected object queue;

void init_user_message()
{
    queue = new(_QUEUE,file_name(this_object())+"_message");
}

int add_user_msg(object ob,string str,object entity,object other){
    return queue->push(new(USER_MSG,ob:ob,str:str,entity:entity,other:other));
}

varargs int add_user_info(string str,object ob){
    return queue->push(new(USER_MSG,ob:ob,str:str,entity:0,other:0));
}

int  user_msg_length(){return queue->length();}

void user_output_one()
{
    string str="";
    USER_MSG u_msg = queue->pop();
    if(!u_msg)
        return;
    if(!queue->length())
        this_object()->enable_command();
    if(objectp(u_msg->ob))
        if(inherits(_MXP, u_msg->ob))
            str += "【"+ u_msg->ob->print_name(this_object()) +"】:";
    str += u_msg->str;
    message("USER",str,this_object());
}
