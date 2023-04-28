/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-28 16:49:25
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-28 17:15:37
 * @FilePath: \mysticism-mud\inherit\summon\summon_data.c
 * @Description: 召唤物属性类，处理战斗过程中召唤物的数值变化
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
/*
 *召唤物初始化必备属性：HP,type
*/
inherit _CLEAN_UP;

nosave protected int hp,type;
nosave protected object dbase;

varargs void init(int hp_in,int type_in,mapping status)
{
    hp = hp_in;
    type = type_in;
    if(status !=0 )
    {
        dbase = new(_DBASE);
    }
}

int remove()
{
    if(dbase)
        destruct(dbase);
    destruct(this_object());
    return 1;
}
