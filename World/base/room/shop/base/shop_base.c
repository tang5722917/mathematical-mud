/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-14 19:58:10
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-07 17:33:54
 * @FilePath: \mysticism-mud\World\base\room\shop\base\shop_base.c
 * @Description:  买卖行为基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <shop.h>

//本商店物品list
mixed *list_obj = ({});

string list_handle()
{
    string str = "";
    if(!arrayp(list_obj) || (!sizeof(list_obj)))
        return "此处不存在售卖的物品";
    else 
    {
        foreach ( mixed list_item in list_obj)
        {
            str += list_item->item + "\n";
        }
        return str;
    }
}

int buy_handle(){
    return 0;
}

int sell_handle(){
    return 0;
}

SHOP_ITEM shop_item(string item, object value, string entity, int num){
    return new(SHOP_ITEM,item:item,value:value,entity:entity,num:num);
}

void add_shop_item(string item, object value, string entity, int num)
{
    mixed item_s;
    item_s = shop_item(item, value, entity, num);
    if(!arrayp(list_obj))
        list_obj = ({});
    list_obj += ({item_s});
}
