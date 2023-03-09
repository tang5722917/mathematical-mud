inherit CORE_CLEAN_UP;

#include <ansi.h>

object combat;

varargs void create(object *ob1,object *ob2,object env)
{
    if((ob1 !=0) && (ob2!=0))
    {
    write(BRED "                                               
                开始战斗！                     
                                               \n" NOR);
    }

    if((sizeof(ob1)==1) &&(sizeof(ob2)==1))
    {
        if(env == 0)
            combat = new(CORE_STD_FIGHT_S,ob1[0],ob2[0]);
    }
    else
    {
        if(env == 0)
            combat = new(CORE_STD_FIGHT_M,ob1,ob2);
    }
    write(combat->fight_main_UI());
}

