/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-07 15:23:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-07 17:26:32
 * @FilePath: \mysticism-mud\include\shop.h
 * @Description: 买卖行为头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#ifndef SHOP_H
#define SHOP_H

#define SHOP_ITEM class list_item
class list_item{
    string item;      //名称
    object value;       //售价
    string entity;      //物品object
    int    num;         //数量
}

#endif
