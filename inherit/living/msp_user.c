/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-31 10:53:44
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-31 16:44:03
 * @FilePath: \mysticism-mud\inherit\living\msp_user.c
 * @Description: MSP 游戏声音控制基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

int msp_oob(string req)
{
    if(MYSTICISM_SOUND)
    {
        efun::telnet_msp_oob(req);
        write("Start play sound!\n");
        return 1;
    }
    else return 0;
}

string msp_play_start(string sound)
{
    msp_oob("!!MUSIC("+sound+" L=1 V=100)");
}
