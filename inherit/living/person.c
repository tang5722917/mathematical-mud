inherit _LIVING;

#include <ansi.h>

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
    string name;
    string * honor_name = ({"先生","女士","阁下","殿下","冕下"}) ;
    if(ob->query("gender") == "女性")
        name = ob->query("name")+honor_name[1];
    else name = ob->query("name")+honor_name[0];
    return name;
}

void person_setup()
{
    living_setup();
}
