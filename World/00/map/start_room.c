// 标准室内环境模板STD_ROOM
#include <ansi.h>

inherit CORE_STD_ROOM;

void create()
{
    set("short", "神秘空间");
    set("long", "四周弥漫着灰雾，朦胧、模糊、无边无际。\n    但前方好像有一个看不清的人影。");
    set("dq", 0); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(0, 0, 0, 0); // 设置所属地区和x,y,z坐标
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
}