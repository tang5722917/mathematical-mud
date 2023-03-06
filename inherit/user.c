
inherit  CORE_STD_PERSON;
inherit _USER_COMBAT_RECORD;
inherit _USER_GMCP;
inherit _USER_QUEST;

#include <ansi.h>


//user status
//是否正在战斗
protected int user_status_fight=0;


int is_fight_user()
{
    return user_status_fight;
}

