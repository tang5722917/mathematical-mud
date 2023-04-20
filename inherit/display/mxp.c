/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-20 20:21:45
 * @FilePath: \mysticism-mud\inherit\display\mxp.c
 * @Description: MXP输出基类
 *               提供MXP输出函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <mxp.h>

string mxp_name(){return "名称";}
string mxp_explain(){return "对名称的解释";}

string * print_mxp_name_all(int type) {
    string *str,s,c;
    str = ({});
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
        case EQUIP:
            c += "orange";
            break;
        case SUMMON:
            c += "fuchsia";
            break;
        case OTHER:
            c += "white";
    } 
    c +=">";
    s = c+"<A \"Card\" hint=\"名称：" + mxp_name() +" 效果："+ mxp_explain() + "\">"+mxp_name()+"</A></C>";
    str += ({s});
    str += ({mxp_name()});
    str += ({mxp_explain()});
    return str;
}

string print_mxp_name(int type) {
    string *str = print_mxp_name_all(type);
    if (MXP_USER(this_player()) == 1 )
        return str[0];
    else return str[1];
}

string mxp_sprintf(string * str,int width,object ob)
{
    string ps;
    if(MXP_USER(ob))
    {
        if(width <= strwidth(str[1]))
            return str[0];
        else
            return str[0]+repeat_string(" ",width-strwidth(str[1]));
    }
    else
    {
        ps = "%-"+width+"s";
        return sprintf(ps,str[1]);
    }
}
