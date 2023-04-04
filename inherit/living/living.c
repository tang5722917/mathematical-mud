#include <dbase.h>
#include <ansi.h>

inherit CORE_LIVING ;
inherit INHERIT_PATH "living/status_value" ;
inherit INHERIT_PATH "living/status_mystic" ;
inherit INHERIT_PATH "living/status_affect" ;
inherit CORE_STD_TEST;

//living status
//是否可以战斗
protected int living_status_fight=0;
//是否可以被复制
protected int living_status_copy=0;
//是否是一个复制的品
protected int living_copy=0;
// 该生物是否可见
protected int living_visible=1;


int is_fight_living()
{
    return living_status_fight;
}

//0 不可以攻击，1可以攻击
void set_fight_living(int is_fight_living)
{
    living_status_fight = is_fight_living;
}

int is_copy_living()
{
    return living_status_copy;
}

int is_copy()
{
    return living_copy;
}

int is_visible()
{
    return living_visible;
}

//0 默认不可见，1默认可见
void set_visible(int is_visible)
{
    living_visible = is_visible;
}


//look 接口函数，处理被look事件
void look(object me,object env){}

// search接口函数，处理search事件
void search(object me,object env){write("没有什么特别的发现。\n ");}
//answer 接口函数，处理被ask事件
void answer(object me,object env){write("你近视吗！这个东西怎么会回答你的问题\n ");}
//honor_name 称呼接口
string honor_name(object me,object ob){return " 它";}
//fight 战斗接口
object * fight(object me,object ob){write("你怎么这么暴力，动不动就打架！\n "); return 0;}

// 角色激活  
void setup()
{
    seteuid(getuid(this_object()));
    set_heart_beat(1);
    enable_living(); // COMMAND 中定义的生物激活方法
    CHAR_D->setup(this_object());
}

//接口，定义该生物的战斗类型，具体由子类实现
string combat_env(object env){return 0;}
//接口，定义该生物的战斗脚本，具体由子类实现
string combat_env(object env，int rank){return 0;}
// 从游戏中移除这个生物
void remove()
{
    destruct(this_object());
}
