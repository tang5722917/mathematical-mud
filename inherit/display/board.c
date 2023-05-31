/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-07 17:33:46
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-31 19:12:03
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

//输出一个方形输出框, info 为输出字符串, max_col为一行最多字符数，超出则自动换行
varargs string board_print(string info, int max_col,int type)
{
    string str="",s,s0;
    int col,k,len;
    col = sizeof(info);
    if(max_col > 0){
        str+=board_top_line(max_col+2,type);
        k = 0;
        s = "";
        len = strlen(info);
        while(k < len)
        {
            while((k < len) && (strwidth(s) < max_col))
            {
                s0 = info[k..k];
                k += 1;
                if((s0 == "
") ||(s0 == "\n"))
                    break;
                else
                    s += s0;
            }
            if(strwidth(s) > max_col )
            {
                s = s[0 .. strlen(s)-2];
                k -= 1;
            }
            s += repeat_string(" ",max_col - strwidth(s));
            str+=VERLINE+s+VERLINE+"\n";
            s = "";
        }
        str+=board_bottom_line(max_col+2,type);
    }
    else{ 
        str+=board_top_line(col+2,type);
        str+="|"+info+"|\n";
        str+=board_bottom_line(col+2,type);
    }
    return str;
}
