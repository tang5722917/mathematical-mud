inherit PATH_DIR "inherit/living" ;

#include <ansi.h>


void create()
{
    property_visible=1;
}

//answer 接口函数，处理被ask事件
void answer(object me,object env){write("不清楚你要问什么\n ");}

//say 接口函数，处理被say事件
void sayinfo(object me,object env){write("你好\n ");}

// pray接口函数，处理pray事件
void pray(object me,object env){write("....... 不清楚向那位神灵祈祷 \n");}

// blessing接口函数，处理blessing事件
void blessing(object me,object env){write("祝你好运，朋友！\n ");}

// pray_gesture 接口函数，处理pray_gesture事件
void pray_gesture(object me,object env){}

string honor_name(object me, object ob)
{
    string * honor_name = ({"你","您","阁下","殿下","冕下"}) ;
    return "你";
}

