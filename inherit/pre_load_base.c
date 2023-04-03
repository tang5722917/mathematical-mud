/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 18:35:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-03 18:48:43
 * @FilePath: \mysticism-mud\inherit\pre_load_base.c
 * @Description: 预加载基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 nomask protected mapping SYS_OBJ;
string ob_name()
{
    return "";
}

 void add_obj(string obj_path,string obj_name)
 {
     object o;
     if (!mapp(SYS_OBJ))
        SYS_OBJ = ([]);
     o = load_object(obj_path);
     if(o == 0)
        debug_message("[" + ctime() + "]导入"+ob_name()+"对象错误");
     SYS_OBJ[obj_name]=o;
 }

 object query_sysobj(string obj_name)
 {
    object o;
    o = SYS_OBJ[obj_name];
    if (o == 0)
        debug_message("[" + ctime() + "]错误的"+ob_name()+"对象调用");
    return o;
 }
