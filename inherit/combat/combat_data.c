inherit CORE_CLEAN_UP;

//战斗过程信息
protected string *fight_info;
//ob1 手牌序列， PVE中的玩家
protected object *ob1_card;
//ob2 手牌序列， PVE中的电脑
protected object *ob2_card;
//ob1 状态序列， PVE中的玩家
protected object *ob1_status;
//ob2 状态序列， PVE中的电脑
protected object *ob2_status;
//ob1 装备序列， PVE中的玩家
protected object *ob1_equip;
//ob2 装备序列， PVE中的电脑
protected object *ob2_equip;
//ob1 召唤物序列， PVE中的玩家
protected object *ob1_summon;
//ob2 召唤物序列， PVE中的电脑
protected object *ob2_summon;
//公共物序列
protected object *env_obj;

/*
string add_card(object *ob, object o)
{
    ob += ({o});
    return "获得能力牌："+ o->card_name();
}
*/
