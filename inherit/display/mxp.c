/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-03 19:14:58
 * @FilePath: \mysticism-mud\inherit\display\mxp.c
 * @Description: MXP输出基类
 *               提供MXP输出函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <mxp.h>

string mxp_name(){return "名称";}
string mxp_explain(){return "对名称的解释";}

varargs string * print_mxp_name_all(int type, string input_str) {
    string *str,s,c;
    string title = "效果";
    str = ({});
    c = "<C FORE=";
    switch(type)
    {
        case MXP_MYSTIC:
            c += "cyan";
            break;
        case MXP_CARD:
            c += "aqua";
            break;
        case MXP_STATUS:
            c += "gold";
            break;
        case MXP_PROPERTY:
            c += "green";
            break;
        case MXP_EQUIP:
            c += "orange";
            break;
        case MXP_SUMMON:
            c += "fuchsia";
            break;
        case MXP_LIV_1:
            c += "white BACK=green";
            title = "介绍";
            break;
        case MXP_LIV_2:
            c += "white BACK=orange";
            title = "介绍";
            break;
        case MXP_LIV_3:
            c += "white BACK=red";
            title = "介绍";
            break;
        case MXP_MAP:
            c += "black BACK=white";
            title = "介绍";
            break;
        case MXP_OTHER:
            c += "white";
            break;
    } 
    c +=">";
    if(!stringp(input_str)){
        s = c+"<A \"Card\" hint=\"名称：" + mxp_name() +" "+title+"："+ mxp_explain() + "\">"+mxp_name()+"</A></C>";
        str += ({s});
        str += ({mxp_name()});
    }
    else{
        s = c+"<A \"Card\" hint=\"名称：" + mxp_name() +" "+title+"："+ mxp_explain() + "\">"+input_str+"</A></C>";
        str += ({s});
        str += ({input_str});
    }
    str += ({mxp_explain()});
    return str;
}

varargs string print_mxp_name(int type,object user,string input_str) {
    string *str = print_mxp_name_all(type,input_str);
    if (MXP_USER(user) == 1 )
        return str[0];
    else return str[1];
}

string print_mxp_name_tab(int type,object user) {
    string *str = print_mxp_name_all(type);
    if (MXP_USER(user) == 1 )
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
