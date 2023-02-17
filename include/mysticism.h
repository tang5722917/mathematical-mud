/*** 
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-02-17 15:02:16
 * @FilePath: \mysticism-mud\include\mysticism.h
 * @Description: 
 * @
 * @Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved. 
 */
#ifndef MYSTICISM_H
#define MYSTICISM_H

/* 游戏目录 */
#define PATH_DIR "/"

// 游戏driver版本
#define VERSION "0.0.1"

/* 核心对象 */
#define MYSTICISM_LOGIN_OB PATH_DIR "system/obj/login"

/* 守护进程 */
#define MYSTICISM_LOGIN_D  PATH_DIR "system/daemons/login_d"

// 游戏管理员账号
#define WIZARD  "mysticism"

// 游戏欢迎界面
#define MOTD    PATH_DIR "World/front-page/MOTD1"

/* 守护进程 */
#define LOGIN_D     MYSTICISM_LOGIN_D

#endif
