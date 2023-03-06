#include <ansi.h>
inherit CORE_STD_PROPERTY;

void create()
{
    set_property_init(0,0,1,1,({"???"}),"一个奇怪的光团");
    set("long", HIC "普通的一个市民" NOR);
    write("神秘光团 \n");
    debug_message("[" + ctime() + "] 初始地图");
    debug_message("[" + ctime() + "]"+ environment(this_object()));
}