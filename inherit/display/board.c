/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 17:33:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-10 19:36:59
 * @FilePath: \mysticism-mud\inherit\display\board.c
 * @Description: 各种方形显示模板
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <display.h>
#include <mxp.h>
inherit _MXP;

//输出方框上端
varargs string board_top_line(int col,int type)
{
    string s;
    if(col < 2)
        col = 2;
    s=TOPLEFT;
    s+=repeat_string(HORLINE,col-2);
    s+=TOPRIGHT+"\n";
    return s;
}
//输出方框下端
varargs string board_bottom_line(int col,int type)
{
    string s;
    if(col < 2)
        col = 2;
    s=BOTLEFT;
    s+=repeat_string(HORLINE,col-2);
    s+=BOTRIGHT+"\n";
    return s;
}

//输出一个方形输出框
varargs string board_print(string info, int col,int type)
{
    string str;
    str = "";
    str+=board_top_line(col,type);
    str+=board_bottom_line(col,type);
    return str;
}
