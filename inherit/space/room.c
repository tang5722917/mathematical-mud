/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-20 06:34:48
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-29 19:28:11
 * @FilePath: \mysticism-mud\inherit\space\room.c
 * @Description: 标准ROOM基类
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "/space/room_base";
inherit _MXP;
//玩家进入后发生事件
void event_enter(object user){return;}

//MXP 显示
string mxp_name(){return get_room_name();}
string mxp_explain(){return long();}

string print_name(object user){return print_mxp_name(11,user);}
