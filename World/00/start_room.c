/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 19:27:57
 * @FilePath: \mysticism-mud\World\00\start_room.c
 * @Description: 初始ROOM
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

// 标准室内环境模板STD_ROOM
#include <ansi.h>
#include <game_world.h>

inherit CORE_STD_ROOM;
#include <task.h>
void create()
{
    set("short", "神秘空间");
    set("long", "四周弥漫着灰雾，朦胧、模糊、无边无际。\n    耳畔想起了时而细密，时而尖锐，时而虚幻，时而诱人，时而狂躁，时而疯癫的低语
    前方好像有一个模糊的人影。你想仔细看，但由于灰雾的笼罩没办法看清\n(可以使用look或l命令来进一步查看(例如:l ?????))");
    set("dq", 0); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(0, 0, 0, 0,"未知区域"); // 设置所属地区和x,y,z坐标
    set("no_get", 1); // 是否禁止拾起
    set("no_drop", 1); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
    set("objects",([
        PATH_00_NPC  "start_up_npc":1,
        PATH_00_NPC  "start_up_fight":1
    ]));

    setup();
}
//处理色出生身份选择及出生地
void do_newbie_choice(mixed *confirm_result,object user)
{
    //出生地选择+出生角色初始化
    if(confirm_result[0][1] == 0) //出生地：鲁恩
    {
        switch(confirm_result[1][1])
        {
            case 0:              //黑夜女神
                load_object(RELIGION_NIGHT_D)->newbie_init(user);
                break;
        }
    }
}

//进行角色出生身份选择
void newbie_choice(object user)
{
    string str;     
    mixed ch = ({});
    object ob = new(TASK_CHOICE);
    function f = (: do_newbie_choice :);
    ob->init(user);
    str  = "昏昏沉沉间你好像想起一点东西。\n";
    ob->add_choice_title_info(str);
    str = "    请选择你的出生地点：\n";
    ch += ({str});
    str = "    0  鲁恩 \n";
    ch += ({({str,0})});
    ob->add_choice(ch);
    str  = "    请选择你信仰的神灵：\n";
    ch  = ({str});
    str = "    0  黑夜女神\n";
    ch += ({({str,0})});
    /*
    str = "    1  风暴之主\n";
    ch += ({({str,1})});
    str = "    2  蒸汽之神\n";
    ch += ({({str,2})});
    */
    ob->add_choice(ch);
    //完成选择确认后行为
    ob->do_confirm_choice(f);
    ob->start();
}
