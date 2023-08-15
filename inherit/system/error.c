/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-10 19:53:19
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-15 12:58:14
 * @FilePath: \mysticism-mud\inherit\system\error.c
 * @Description: 错误处理基类,整合常见错误类型
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit _CLEAN_UP;
nosave protected string err,err_ob;

private string *err_arr=({
    "传入的对象引用为0",
    "对象非living类及其子类",
    "输入的文件夹路径不存在",
    "对象非entity类及其子类",
    "状态机转换状态不存在",
    "dbase 中插入重复key值",
    "dbase 中不存在该项属性"
});

void init(object ob)
{
    err_ob = file_name(ob);
}

int object_missing(mixed ob)
{
    if(objectp(ob))
        return 0;
    err = catch{
        throw("错误原因："+ err_arr[0]+ " : " + sprintf("%O",ob));
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err);
    return 1;
}

int is_living(object ob)
{
    if(objectp(ob))
        if(inherits(_LIVING,ob))
            return 0;
    err = catch{
        throw("错误原因："+ err_arr[1]+ " : " + sprintf("%O",ob));
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err);    
    return 1;
}

int is_entity(object ob)
{
    if(objectp(ob))
        if(inherits(INHERIT_PATH "entity/entity",ob))
            return 0;
    err = catch{
        throw("错误原因："+ err_arr[3]+ " : " + sprintf("%O",ob));
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err);    
    return 1;
}

int is_path(string path)
{
    if(stringp(path))
        if(sizeof(get_dir(path)))
            return 0;
    err = catch{
        throw("错误原因："+ err_arr[2] + " : " + path);
    };
    debug_message("[" + ctime() + "]错误所在的对象："+err_ob);
    debug_message("[" + ctime() + "]"+err); 
    return 1;
}

int invalid_state(object ob,int num)
{
    debug_message("[" + ctime() + "]错误所在的对象："+file_name(ob));
    debug_message("[" + ctime() + "]"+err_arr[4]+" 状态编号："+ num);    
    return 1;
}

int repeat_dbase(object ob,string key)
{
    if(!ob->definedp(key))
        return 0;
    debug_message("[" + ctime() + "]错误所在的对象："+file_name(ob));
    debug_message("[" + ctime() + "]"+err_arr[5]+" 插入key值："+ key);    
    return 1;
}

int miss_dbase(object ob,string key)
{
    if(ob->definedp(key))
        return 0;
    debug_message("[" + ctime() + "]错误所在的对象："+file_name(ob));
    debug_message("[" + ctime() + "]"+err_arr[6]+" 查找属性值："+ key);    
    return 1;
}
