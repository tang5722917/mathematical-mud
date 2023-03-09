inherit CORE_CLEAN_UP;

#include <ansi.h>

#define FIGHT_PVE 0
#define FIGHT_PVP 1

//战斗计时(秒)
protected nosave int fight_time=0;
//战斗回合
protected nosave int fight_round=0;

object combat;

varargs void create(object *ob1,object *ob2,int fight_type,object env)
{
    fight_time=0;
    fight_round=0;
    if((ob1 !=0) && (ob2!=0))
    {
        message("FIG",BRED "                                               
                开始战斗！                     
                                               " NOR,ob1+ob2);
    }
    else return ;
    if(fight_type == FIGHT_PVE){
    if((sizeof(ob1)==1) &&(sizeof(ob2)==1))
    {
        if(env != 0)
            combat = new(CORE_STD_FIGHT_S,ob1[0],ob2[0],env);
        else return;
    }
    else
    {
        if(env != 0)
            combat = new(CORE_STD_FIGHT_M,ob1,ob2,env);
        else return;
    }}
    else {
        ;  //TBD
    }
    combat->print_fight(combat->fight_init());
    set_heart_beat(1);
    combat->print_fight(combat->fight_main_UI(fight_time,fight_round));
}

void heart_beat( void )
{
    fight_time += 1;  //时间加1s
}


