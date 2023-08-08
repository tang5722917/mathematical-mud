/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-03 19:36:37
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-08 15:39:10
 * @FilePath: \mysticism-mud\World\base\room\module\paizi_base.c
 * @Description:  牌子组件，用来在建筑物前放置一个牌子
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit CORE_STD_TEST;
inherit _NAME;
inherit _MOVE;
inherit _DBASE;
inherit _MESSAGE;
inherit _BOARD;
#include <ansi.h>
#include <mxp.h>


//默认可见
int env_display(){return 1;}

void create()
{
    set_name(HBWHT BLK "牌子" NOR,({"paizi"}));
}

void print_paizi(string str,int col)
{
    string s;
    s = board_print(str, col);
    set("long", s);
}

string paizi_list(string id){
    string str ="list "+id+"   ---  查看本店物品 \n";
    return str;
}

string paizi_buy(string id){
    string str = "buy "+id+"    ---  购买物品 \n";
    return str;
}

string paizi_sell(string id){
    string str = "sell "+id+"  ---  出售物品 \n";
    return str;
}
string paizi_cmd(string * cmds,string id)
{
    string s="";
    foreach (string str in cmds)
    {
        switch (str)
        {
            case "list":
                s += paizi_list(id);
                break;
            case "buy":
                s += paizi_buy(id);
                break;
            case "sell":
                s += paizi_sell(id);
                break;
        }
    }
    return s;
}
