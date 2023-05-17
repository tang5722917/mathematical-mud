/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 11:37:48
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-17 14:47:43
 * @FilePath: \mysticism-mud\inherit\living\user_message.c
 * @Description: 玩家Message 处理
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
//user接受的NPC对话 massage
#include <user.h>

nosave protected USER_MSG *u_msg;

void init_user_meaage()
{
    u_msg = ({});
}

USER_MSG get_user_msg(object ob,string *str,object *entity){
    return new(USER_MSG,ob:ob,str:str,entity:entity);
}

void user_output_one()
{
    
}
