/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-14 14:28:20
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-15 13:20:07
 * @FilePath: \mysticism-mud\inherit\std\dbase.c
 * @Description: 继承自mudcore dbase,扩展一些功能
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit CORE_DBASE;
//dbase 中map存在key返回1，否则返回0
int definedp(string prop){
    if (!mapp(dbase)){
        dbase = ([]);
        return 0;
    }
    return (!undefinedp(dbase[prop]));
}

int temp_definedp(string prop){
    if (!mapp(dbase)){
        dbase = ([]);
        return 0;
    }
    return (!undefinedp(tmp_dbase[prop]));
}

//返回dbase中条目数
int dbase_sizeof()
{
    return sizeof(dbase);
}
