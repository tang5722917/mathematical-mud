/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-27 15:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-27 19:52:52
 * @FilePath: \mysticism-mud\inherit\card.c
 * @Description: 卡牌实现基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <ansi.h>
#include <mxp.h>

string card_name(){return "手牌";}
string card_explain(){return "打出手牌，并获得相关效果";}

public string print_card_name() {
    string s = "<A \"Card\" hint=\"名称：" + card_name() +" 效果："+ card_explain() + "\">"+card_name()+"</A>";
    if (USER_MXP == 1 )
        return s;
    else write(card_name());
}
