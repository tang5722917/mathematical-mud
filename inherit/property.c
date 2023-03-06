#include <ansi.h>

inherit _NAME;
inherit _MESSAGE;
inherit _MOVE;


protected mapping property;
//是否可以移动ROOM
protected int property_move = 0;
//是否可以拾取
protected int property_get = 0;
//是否默认可见
protected int property_visible = 1;
//物品编号
protected int property_number = 0;


int is_move()
{
    return property_move;
}

int is_get()
{
    return property_get;
}

int is_visible()
{
    return property_visible;
}

int prop_vnumber()
{
    return property_visible;
}

// 设置属性值
mixed set(string pron, mixed value)
{
    if (!mapp(property))
        property = ([]);
    return property[pron] = value;
}

// 获取属性值
mixed query(string pron)
{
    int data;
    data = property[pron];
    return data;
}

void set_property_init(int move,int get,int visible,int num,string* id,string name)
{
    property_move = move;
    property_get = get;
    property_visible = visible;
    property_number = num;
    set_name(YEL+name+NOR,id);
}