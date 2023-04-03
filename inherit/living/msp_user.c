/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-31 10:53:44
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-03 10:58:49
 * @FilePath: \mysticism-mud\inherit\living\msp_user.c
 * @Description: MSP 游戏声音控制基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <msp.h>

protected int msp_enable;

int msp_print(string req)
{
    if(MYSTICISM_SOUND)
    {
        efun::telnet_msp_oob(req);
        write("Start play sound!\n");
        return 1;
    }
    else return 0;
}

int msp_play_start(string sound)
{
    return msp_print("!!MUSIC("+sound+" L=1 V=100)");
}

void set_msp_enable(int status)
{
    msp_enable = status;
}

int get_msp_enable()
{
    return msp_enable;
}
