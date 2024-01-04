/***
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-17 10:19:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-22 17:36:41
 * @FilePath: \mysticism-mud\include\mysticism.h
 * @Description:
 * @
 * @Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved.
 */
#ifndef MYSTICISM_H
#define MYSTICISM_H

/* 游戏目录 */
#define PATH_DIR            "/"
#define INHERIT_PATH        PATH_DIR "inherit/"
#define SOUND               PATH_DIR "World/src/sound/"     
#define WORLD_PATH          PATH_DIR "World/"
#define TEST_DATA           PATH_DIR "test/test_data/"

/* 核心对象 */
#define MYSTICISM_LOGIN_OB PATH_DIR "system/obj/login"
#define SYSTEM_OBJ PATH_DIR "system/obj/pre_object"

/* 守护进程 */
#define MYSTICISM_LOGIN_D   PATH_DIR "system/daemons/login_d"
#define MYSTICISM_CHAR_D    PATH_DIR "system/daemons/char_d"
#define MYSTICISM_FIGHT_D   PATH_DIR "system/daemons/combat_d"
#define MYSTICISM_COMMAND_D PATH_DIR "system/daemons/command_d"
#define MYSTICISM_TIME_D    PATH_DIR "system/daemons/time_d"
#define MYSTICISM_SYS_DB_D  PATH_DIR "system/daemons/db/sys_db_d"   
#define MYSTICISM_NATURE_D  PATH_DIR "system/daemons/nature_d"
#define MYSTICISM_INTERMUD_D             PATH_DIR "system/daemons/intermud/i2d"
#define MYSTICISM_INTERMUD_SERVICE(x)    (PATH_DIR "system/daemons/intermud/_" + x)
/* inherit 特性文件 */
#define CORE_STD_CAMP           PATH_DIR "inherit/camp/camp"
#define CORE_STD_COMMON         PATH_DIR "inherit/entity/common"
#define CORE_STD_PRE            PATH_DIR "inherit/system/pre_load_base"
#define CORE_STD_ROOM           PATH_DIR "inherit/space/room"
#define CORE_STD_AREA           PATH_DIR "inherit/space/area"
#define CORE_STD_PERSON         PATH_DIR "inherit/living/person"
#define CORE_STD_NPC            PATH_DIR "inherit/living/living_npc"
#define CORE_STD_PERSON_NPC     PATH_DIR "inherit/living/person_npc"
#define CORE_STD_PROPERTY       PATH_DIR "inherit/entity/property"
#define CORE_STD_MYSTIC         PATH_DIR "inherit/mystic/mystic"
#define CORE_STD_TASK           PATH_DIR "inherit/task/task"
#define CORE_STD_TEST           PATH_DIR "inherit/system/test"
#define CORE_STD_FIGHT_S        PATH_DIR "inherit/combat/combat_single"
#define CORE_STD_FIGHT_M        PATH_DIR "inherit/combat/combat_multi"
#define CORE_STD_SCRIPT         PATH_DIR "inherit/combat/combat_script"
#define CORE_STD_CARD           PATH_DIR "inherit/entity/card"
#define CORE_STD_EQUIP          PATH_DIR "inherit/entity/equip"
#define CORE_STD_SUMMON         PATH_DIR "inherit/entity/summon"
#define CORE_STD_STATUS         PATH_DIR "inherit/entity/status"
#define CORE_STD_MATERIALS      PATH_DIR "inherit/entity/materials"
#define CORE_STD_STORAGE        PATH_DIR "inherit/entity/storage"
#define CORE_STD_MYROOM         PATH_DIR "inherit/space/myroom_base"
#define CORE_STD_MYAREA         PATH_DIR "inherit/space/myarea_base"
/* inherit 特性文件 (覆盖用)*/
#define _BOARD          PATH_DIR "inherit/display/board"
#define _CAMP           PATH_DIR "inherit/living/status_camp"
#define _ERR            PATH_DIR "inherit/system/error"
#define _DB             PATH_DIR "inherit/system/db"
#define _DBASE          PATH_DIR "inherit/std/dbase"
#define _LIVING         PATH_DIR "inherit/living/living"
#define _LIST           PATH_DIR "inherit/std/list"
#define _USER           PATH_DIR "inherit/living/user"
#define _USER_QUEST     PATH_DIR "inherit/task/user_quest"
#define _USER_GMCP      PATH_DIR "inherit/living/gmcp_user"
#define _COMMAND        PATH_DIR "inherit/system/command"
#define _MESSAGE        PATH_DIR "inherit/display/message"
#define _MXP            PATH_DIR "inherit/display/mxp"
#define _MOVE           PATH_DIR "inherit/space/move"
#define _QUEUE          PATH_DIR "inherit/std/queue"
#define _STATE          PATH_DIR "inherit/std/state"
#define _STATE_M        PATH_DIR "inherit/std/state_machine"
#define _TEST_DATA      PATH_DIR "test/test_inherit/test_base"

/* 守护进程 (覆盖用)*/
#define TIME_D      MYSTICISM_TIME_D
#define LOGIN_D     MYSTICISM_LOGIN_D
#define CHAR_D      MYSTICISM_CHAR_D
#define FIGHT_D     MYSTICISM_FIGHT_D
#define COMMAND_D   MYSTICISM_COMMAND_D
#define NATURE_D    MYSTICISM_NATURE_D
#define INTERMUD_D  MYSTICISM_INTERMUD_D

// START_ROOM   游戏出生点
#define START_ROOM  WORLD_PATH "00/start_room"
#define Game_World  WORLD_PATH "world_create"

// CMD_PATH_WIZ   巫师指令
#define CMD_PATH_WIZ ({PATH_DIR "cmds/wizard/"})
// CMD_PATH_STD   玩家指令
#define CMD_PATH_STD ({PATH_DIR "cmds/player/" ,PATH_DIR "verbs/common/"})
#define VERB_DIR PATH_DIR "verbs/"

/* 核心对象 (覆盖用)*/
#define VOID_OB     PATH_DIR "system/obj/void"
#define USER_OB     PATH_DIR "system/obj/user"

#endif
