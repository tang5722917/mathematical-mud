/*** 
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-02-25 17:19:23
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 15:04:11
 * @FilePath: \mysticism-mud\World\include\game_world.h
 * @Description: 
 * @
 * @Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#define Know_how_version  "0.0.1"
#define World_version     "0.0.1"
//World Time
#define World_year        1349
#define World_month       6
#define World_day         18

//基础游戏内容路径
#define PATH_BASE      PATH_DIR "World/base/"
#define MYSTIC_PATH    PATH_BASE "mystic/"
#define MYSTIC_CARD    PATH_BASE "card/"
#define MYSTIC_SKILL   PATH_BASE "skill/"
#define MYSTIC_SUMMON  PATH_BASE "summon/"
 //0.x版本游戏内容路径
#define PATH_00      PATH_DIR "World/00/"
#define PATH_00_NPC  PATH_00 "npc/"
#define PATH_00_MAP  PATH_00 "map/"
#define PATH_00_PRO  PATH_00 "property/"
#define PATH_00_FIG  PATH_00 "combat/"
#define PATH_00_SCR  PATH_00 "script/"
#define PATH_00_MYH  PATH_00 "mystic/"
#define PATH_00_STA  PATH_00 "status/"
#endif //GAME_WORLD
