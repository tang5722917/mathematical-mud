/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-29 16:13:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-29 17:33:44
 * @FilePath: \mysticism-mud\system\obj\pre_object.c
 * @Description: 预加载的系统Obect
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 nomask protected mapping SYS_OBJ;

 void add_obj(string obj_path,string obj_name)
 {
     object o;
     if (!mapp(SYS_OBJ))
        SYS_OBJ = ([]);
     o = load_object(obj_path);
     if(o == 0)
        debug_message("[" + ctime() + "]导入系统对象错误");
     SYS_OBJ[obj_name]=o;
 }

 object query_sysobj(string obj_name)
 {
    object o;
    o = SYS_OBJ[obj_name];
    if (o == 0)
        debug_message("[" + ctime() + "]错误的系统对象调用");
    return o;
 }
 

 void create()
 {
    add_obj("/system/obj/start_mxp","start_mxp");
    debug_message("[" + ctime() + "]系统对象加载成功 \n");
 } 
