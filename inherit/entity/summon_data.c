/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:49:25
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-13 19:09:59
 * @FilePath: /mysticism-mud/inherit/entity/summon_data.c
 * @Description: 召唤物属性类，处理战斗过程中召唤物的数值变化
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
/*
 *召唤物初始化必备属性：HP,type
*/
inherit _CLEAN_UP;

nosave protected int type;
nosave protected object dbase;
nosave protected object summon;

object get_summon_card(){return card;}
object get_summon_dbase(){return dbase;}

varargs void init(int type_in,mapping status,object su)
{
    type = type_in;
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
