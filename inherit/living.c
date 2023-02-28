#include <dbase.h>
#include <ansi.h>

inherit CORE_LIVING ;
inherit INHERIT_PATH "status_value" ;
inherit INHERIT_PATH "status_mystic" ;
inherit INHERIT_PATH "status_affect" ;

//look 接口函数，处理被look事件
void look(object me){};

// 角色激活  
void setup()
{
    seteuid(getuid(this_object()));
    set_heart_beat(1);
    enable_living(); // COMMAND 中定义的生物激活方法
    CHAR_D->setup(this_object());
}

// 从游戏中移除这个生物
void remove()
{
    destruct(this_object());
}


