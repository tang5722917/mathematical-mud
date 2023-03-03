inherit PATH_DIR "inherit/living" ;

#include <ansi.h>


void create()
{
}

//answer 接口函数，处理被ask事件
void answer(object me){write("不清楚你要问什么\n ");}

//say 接口函数，处理被say事件
void say(object me){write("你好\n ");}

// pray接口函数，处理pray事件
void pray(object me){write("....... 不清楚向那位神灵祈祷 \n");}

// blessing接口函数，处理blessing事件
void blessing(object me){write("祝你好运，朋友！\n ");}

// pray_gesture 接口函数，处理pray_gesture事件
void pray_gesture(object me){}

