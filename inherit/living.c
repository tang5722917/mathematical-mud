#include <dbase.h>

inherit CORE_LIVING ;

//look 接口函数，处理被look事件
void look();

protected object status_value;
protected object status_mystic;
protected object status_affect;

void create()
{
    status_value = new(INHERIT_PATH "status_value");
    status_mystic = new(INHERIT_PATH "status_mystic");
    status_affect = new(INHERIT_PATH "status_affect");
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


