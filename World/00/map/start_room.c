// 标准室内环境模板STD_ROOM
#include <ansi.h>
#include <game_world.h>

inherit CORE_STD_ROOM;

void create()
{
    set("short", "神秘空间");
    set("long", "四周弥漫着灰雾，朦胧、模糊、无边无际。\n    耳畔想起了时而细密，时而尖锐，时而虚幻，时而诱人，时而狂躁，时而疯癫的低语
    前方好像有一个模糊的人影。你想仔细看，但由于灰雾的笼罩没办法看清");
    set("dq", 0); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(0, 0, 0, 0,"未知区域"); // 设置所属地区和x,y,z坐标
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
    set("objects",([
        PATH_00_NPC  "start_up_npc":1
    ]));

    setup();
}