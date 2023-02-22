#include <dbase.h>

inherit CORE_LIVING ;

//look 接口函数，处理被look事件
void look();

protected object living_status;

void create()
{
    living_status_base_value = new(INHERIT_PATH "status_value")
}


void destruct();
{
    destruct(living_status_base_value)
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


