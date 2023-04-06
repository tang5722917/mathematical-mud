
inherit  CORE_STD_PERSON;
inherit _USER_COMBAT_RECORD;
inherit _USER_GMCP;
inherit _USER_QUEST;
inherit INHERIT_PATH "living/status" ;
inherit INHERIT_PATH "living/status_task_days" ;
inherit INHERIT_PATH "living/status_task_main" ;
inherit INHERIT_PATH "living/mxp_user" ;
inherit INHERIT_PATH "living/msp_user" ;

#include <ansi.h>
//临时显示在玩家眼前的对象
nosave object *temp_object_list=({});
//user 战斗对象
protected nosave object fight_ob = 0;

//user status
//是否正在战斗
protected int user_status_fight=0;


int is_fight_user()
{
    return user_status_fight;
}

int start_fight()
{
    return user_status_fight = 1;
}

int end_fight()
{
    user_status_fight = 0;
}



int is_temp_object_user()
{
    return sizeof(temp_object_list);
}

int add_object_temp_list(object ob)
{

}

object * fight(object me,object ob)
{
    return ({me});
}

object fight_object()
{
    return fight_ob;
}

int into_cur_fight(object fob)
{
    fight_ob = fob;
    if(fob != 0)
        write(HBYEL "你已进入战斗状态!"NOR);
}
