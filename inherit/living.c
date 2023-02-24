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

void init_status(string uid)
{
    seteuid(uid);
    status_value = new(INHERIT_PATH "status_value");
    status_mystic = new(INHERIT_PATH "status_mystic");
    status_affect = new(INHERIT_PATH "status_value");
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


