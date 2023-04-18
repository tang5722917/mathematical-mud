/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-10 19:53:19
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-18 15:35:45
 * @FilePath: \mysticism-mud\inherit\system\error.c
 * @Description: 错误处理基类,整合常见错误类型
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CLEAN_UP;
nosave protected string err,err_ob;

private string *err_arr=({
    "传入的对象引用为0",
    "对象非living类及其子类"
});

void init(object ob)
{
    err_ob = file_name(ob);
}

void object_missing(mixed ob)
{
    if(objectp(ob))
        return ;
    err = catch{
        throw("错误原因："+ err_arr[0]);
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err);
}

void is_living(object ob)
{
    if(objectp(ob))
        if(inherits(_LIVING,ob))
            return ;
    err = catch{
        throw("错误原因："+ err_arr[1]);
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err);    
}
