
inherit  CORE_STD_PERSON;
inherit _USER_COMBAT_RECORD;
inherit _USER_GMCP;
inherit _USER_QUEST;
inherit INHERIT_PATH "status" ;
inherit INHERIT_PATH "user_input" ;

#include <ansi.h>
//临时显示在玩家眼前的对象
nosave object *temp_object_list=({});

//user status
//是否正在战斗
protected int user_status_fight=0;


int is_fight_user()
{
    return user_status_fight;
}

int is_temp_object_user()
{
    return sizeof(temp_object_list);
}

int add_object_temp_list(object ob)
{

}



