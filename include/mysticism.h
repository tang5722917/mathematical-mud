/*** 
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-05 00:31:36
 * @FilePath: \mysticism-mud\include\mysticism.h
 * @Description: 
 * @
 * @Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved. 
 */
#ifndef MYSTICISM_H
#define MYSTICISM_H


/* 游戏目录 */
#define PATH_DIR "/"
#define  INHERIT_PATH     PATH_DIR "/inherit/"

// 游戏driver版本
#define VERSION "0.0.1"

/* 核心对象 */
#define MYSTICISM_LOGIN_OB PATH_DIR "system/obj/login"


/* 守护进程 */
#define MYSTICISM_LOGIN_D  PATH_DIR "system/daemons/login_d"
#define MYSTICISM_CHAR_D   PATH_DIR "system/daemons/char_d"


/* inherit 特性文件 */
#define CORE_STD_ROOM           PATH_DIR "inherit/room"
#define CORE_STD_PERSON         PATH_DIR "inherit/person"
#define CORE_STD_NPC            PATH_DIR "inherit/person_npc"
#define CORE_STD_TASK           PATH_DIR "inherit/task"

/* inherit 特性文件 (覆盖用)*/
#define _LIVING         PATH_DIR "inherit/living"
#define _USER           PATH_DIR "inherit/user"
#define _USER_QUEST     PATH_DIR "inherit/user_current"

// 游戏管理员账号
#define WIZARD  "mysticism"

// 游戏欢迎界面
#define MOTD    PATH_DIR "World/front-page/MOTD1"

/* 守护进程 */
#define LOGIN_D     MYSTICISM_LOGIN_D
#define CHAR_D      MYSTICISM_CHAR_D


// START_ROOM   游戏出生点
#define START_ROOM  PATH_DIR "World/00/map/start_room"
#define Game_World  PATH_DIR "World/world_create"

// CMD_PATH_WIZ   巫师指令
#define CMD_PATH_WIZ ({PATH_DIR "cmds/wizard/", PATH_DIR "cmds/player/" ,PATH_DIR "verbs/common/"})
// CMD_PATH_STD   玩家指令
#define CMD_PATH_STD ({PATH_DIR "cmds/player/" ,PATH_DIR "verbs/common/"})

#define VERB_DIR PATH_DIR "verbs/"

/* 核心对象 (覆盖用)*/
#define VOID_OB     PATH_DIR "system/obj/void"
#define USER_OB     PATH_DIR "system/obj/user"


#endif
