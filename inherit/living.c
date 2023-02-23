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

void living_init()
{
    status_value = new(INHERIT_PATH "status_value");
    status_mystic = new(INHERIT_PATH "status_mystic");
    status_affect = new(INHERIT_PATH "status_affect");
    write(WHT "对象初始化" NOR);
    if (status_value == 0)
    write(WHT "初始化错误"NOR);
}

int move_or_destruct(object dest)
{
    destruct( status_value );
    destruct( status_mystic );
    destruct( status_affect );
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


