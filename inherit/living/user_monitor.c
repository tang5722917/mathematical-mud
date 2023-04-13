/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-13 16:42:59
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-13 17:20:39
 * @FilePath: \mysticism-mud\inherit\living\user_monitor.c
 * @Description: USER 输入状态检测
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
//多少次错误输入后强制退出
#include <ansi.h>

#define MAX_ERR_INPUT 100

 //记录每秒输入的命令数
nosave protected int input_num,input_sum; 
nosave protected int input_num_max; 
nosave protected int input_disable; 

void init_user_monitor(int num,int sum,int max)
{
    input_num = num;
    input_sum = sum; 
    input_num_max = max; 
}

int user_input()
{
    object me = this_object();
    input_num += 1;
    input_sum += 1;
    if(input_num > input_num_max)
    {
        input_disable +=1;
        if(input_disable > 0)
        {
            message("SYS",RED "你输入指令的速度太快，请优化您的脚本！\n" NOR,me);
            if(input_disable > MAX_ERR_INPUT )
            {
                message("SYS",RED "你已被强制下线！\n"  NOR,me);   
                me->remove();
            }
            return 1;
        }
    } 
    return 0;
} 
