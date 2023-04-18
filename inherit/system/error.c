/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-10 19:53:19
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-04-18 08:39:23
 * @FilePath: \mysticism-mud\inherit\system\error.c
 * @Description: 错误处理基类,整合常见错误类型
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CLEAN_UP;
nosave protected string err,err_ob;

void object_missing(mixed ob)
{
    err = catch{
        throw("错误原因：传入的对象引用为0")
    }
    debug_message("[" + ctime() + "]错误所在的对象名："+err_ob);
    debug_message("[" + ctime() + "]"+err);
}
