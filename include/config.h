/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-25 19:55:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-25 20:08:48
 * @FilePath: \mysticism-mud\include\config.h
 * @Description: 
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#ifndef CONF_G_H
#define CONF_G_H

// 游戏driver版本
#define VERSION "0.0.1"

//开启调试模式
#define DEBUG_MYSTICISM
//开启GMCP调试模式，打印接收到的GMCP指令
#define DEBUG_GMCP_enable 0
//开启音乐 0 OFF | 1 ON
#define MYSTICISM_SOUND 1
//开启数据库 0 OFF | 1 ON
#define MYSTICISM_DB 1

// 游戏管理员账号
#define WIZARD    "mysticism"
#define AUTOTEST  "autotest"  //自动化测试账号
// 游戏欢迎界面
#define MOTD    PATH_DIR "World/src/front-page/MOTD1"

//游戏内容参数设置
//同时进行的最大任务数
#define MYSTIC_MAX_QUEST 10
//Mail邮箱最多邮件数
#define MYSTIC_MAX_MAIL 100


//intermud
#define MUDLIST_SERVER "118.190.104.241"
#define MUDLIST_SERVER_PORT 5567
#define INTERMUD_MUD_NAME "MYSTICISM-MUD"
#define MUDLIB_NAME "诡秘世界"


#endif
