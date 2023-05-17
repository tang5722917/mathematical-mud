/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 10:48:29
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-17 11:58:16
 * @FilePath: \mysticism-mud\include\user.h
 * @Description: USER 相关头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#ifndef USER_H
#define USER_H

#define INIT_MYS WORLD_PATH "base/mystic/000_mortal"

#define LIV_IN_NUM     INHERIT_PATH "living_d/user_input_num_d"

#define USER_MSG class user_msg 
class user_msg{
    object ob;      //msg 发出者
    string *str;    //msg string
    object *entity;  //msg 附加物品
}



#endif
