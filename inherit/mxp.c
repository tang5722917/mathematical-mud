/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-04 19:38:55
 * @FilePath: \mysticism-mud\inherit\mxp.c
 * @Description: MXP输出基类
 *               提供MXP输出函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <mxp.h>

string mxp_name(){return "手牌";}
string mxp_explain(){return "打出手牌，并获得相关效果";}

public string print_mxp_name(int type) {
    string s,c;
    c = "<C FORE=";
    switch(type)
    {
        case MYSTIC:
            c += "cyan";
            break;
        case CARD:
            c += "blue";
            break;
        case STATUS:
            c += "gold";
            break;
        case PROPERTY:
            c += "green";
            break;
    } 
    c +=">";
    s = c+"<A \"Card\" hint=\"名称：" + mxp_name() +" 效果："+ mxp_explain() + "\">"+mxp_name()+"</A></C>";
    if (MXP_USER(this_player()) == 1 )
        return s;
    else return(mxp_name());
}
