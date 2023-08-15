/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-03 18:35:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-15 12:47:27
 * @FilePath: \mysticism-mud\inherit\system\pre_load_base.c
 * @Description: 预加载基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
nomask protected mapping SYS_OBJ;
nosave protected object *obj;
nosave protected object err;
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
     {
        debug_message("[" + ctime() + "]导入"+ob_name()+"对象错误");
        return;
     }
     if(!arrayp(obj))
        obj = ({});
     obj += ({o});
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


varargs object * load_path_object(string path,string des)
 {
    string * str;
    string s;
    object o,*ob;
    ob = ({});
    if( err->is_path(path))  //判读文件夹是否存在
        return 0;
    if(!arrayp(obj))
        obj = ({});
    str=deep_path_list(path);
    
    foreach (s in str)
    {
        //debug_message(sprintf("%O  %O" ,s,sizeof(pcre_match_all(s,"(\\.h)"))));
        if( sizeof(pcre_match_all(s,"(\\.h)")) == 0)
            o = load_object(s);
        else continue;
        if(o == 0)
        {
            debug_message("[" + ctime() + "]错误的"+ob_name()+"对象调用");
            return 0;
        }
        ob += ({o});
    }
    obj += ob;
    if( stringp(des) )
        debug_message("[" + ctime() + "]成功加载"+ des +"对象数："+sizeof(ob));
    return ob;
}

void ob_load_end(int n)
{
    if(n)
        debug_message("[" + ctime() + "]成功完成"+ob_name()+"加载,共计对象数："+sizeof(obj));
    else
        debug_message("[" + ctime() + "]"+ob_name()+"加载失败");
}

void create()
{
    err = new(_ERR);
    err->init(this_object());
}
