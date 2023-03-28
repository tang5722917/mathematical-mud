/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-28 19:01:42
 * @FilePath: \mysticism-mud\inherit\mxp.c
 * @Description: MXP 状态类
 *               用于记录客户端MXP返回的信息
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <mxp.h>

string card_name(){return "手牌";}
string card_explain(){return "打出手牌，并获得相关效果";}

public string print_card_name() {
    string s = "<A \"Card\" hint=\"名称：" + card_name() +" 效果："+ card_explain() + "\">"+card_name()+"</A>";
    if (USER_MXP == 1 )
        return s;
    else return(card_name());
}
