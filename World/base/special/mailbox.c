/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2024-01-03 17:24:54
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-04 18:51:40
 * @FilePath: \mysticism-mud\World\base\special\mailbox.c
 * @Description: 邮箱基类 - 实现邮件的查看，收取，发送功能
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


inherit CORE_STD_COMMON;
inherit _BOARD;
string common_name(){return "邮箱";}
string common_short(){return "用于收取/发送邮件的装置";}
int common_id(){return 800001;}
//8-common 00 - 表示剧情无关物品 00-全局类物品 01 邮箱
int is_visible() {return 1;}
string id_look(){return "mailbox";}

string common_description(){
    string str,info;
    info = 
@BOARD
          普通邮箱
list            查看邮件列表
open 【数字】   打开查看【数字】对应邮件
BOARD ;
    str = board_print(info, 50);
    return str;
}
