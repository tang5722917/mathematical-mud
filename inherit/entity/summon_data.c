/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:49:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-15 19:18:38
 * @FilePath: \mysticism-mud\inherit\entity\summon_data.c
 * @Description: 召唤物属性类，处理战斗过程中召唤物的数值变化
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
/*
 *召唤物初始化必备属性：type,status,card_object
*/
#include <attack.h>
inherit _CLEAN_UP;

nosave protected int type;
nosave protected object dbase;
nosave protected object card;
nosave protected object user;
nosave protected object summon;

object get_summon_card(){return card;}
object get_summon_dbase(){return dbase;}

varargs void init(int type_in,mapping status,object c,object u,object su)
{
    type = type_in;
    card = c;
    user = u;
    summon = su;
    if( (mapp(status)) && (sizeof(status)))
    {
        dbase = new(_DBASE);
        foreach(mixed k,mixed v in status)
            dbase->set(k,v);
    }
}

mixed query(string key){return dbase->query(key);}
void set(string key,mixed value){dbase->set(key,value);}
int remove()
{
    if(dbase)
        destruct(dbase);
    destruct(this_object());
    return 1;
}
string mxp_sprintf(string * str,int width,object ob){
    return summon->mxp_sprintf(str,width,ob);
}

string * print_mxp_name_all(int type) {
    return summon->print_mxp_name_all(type);
}
string name(){return summon->summon_name();}

void query_sub_attr(string str,int damage)
{
    A_VALUE v;
    v = dbase->query("value");
    switch(str)
    {
        case "hp":
            v->hp -= damage;
    }
    dbase->set("value", v);
}
