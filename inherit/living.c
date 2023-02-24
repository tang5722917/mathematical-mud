#include <dbase.h>
#include <ansi.h>

inherit CORE_LIVING ;

//look 接口函数，处理被look事件
void look();

object status_value;
object status_mystic;
object status_affect;

object query_status_value()
{
    return status_value;
}

void create()
{
    debug_message("开始status_value初始化\n");
    status_value = new(INHERIT_PATH "status_value");

    status_mystic = new(INHERIT_PATH "status_mystic");
    debug_message("开始status_mystic初始化\n");
    status_affect = new(INHERIT_PATH "status_value");
    //status_affect = new(INHERIT_PATH "status_affect");
    debug_message("开始status_affec初始化\n");
    debug_message("living 初始化\n");
}

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


