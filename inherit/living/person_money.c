/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-18 04:56:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-18 04:59:55
 * @FilePath: \mysticism-mud\inherit\living\person_money.c
 * @Description: 货币基类 -- 为person 提供货币支持
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

protected mapping money;

void money_init()
{
    if(!mapp(money))
        money = ([]);
}
