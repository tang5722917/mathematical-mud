/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-14 18:07:57
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-15 05:47:52
 * @FilePath: \mysticism-mud\inherit\std\list.c
 * @Description: List 基类，用于存储类<索引 - 对象>
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

object name_obj,id_obj,list_prop,err;
//type - 0 : 静态对象
//type - 1 : 动态对象
varargs void init(string base_obj)
{
    id_obj = new(_DBASE);  //id用来进行快速筛选
    name_obj  = new(_DBASE); //链接name - id - obj 
    list_prop  = new(_DBASE); //本list属性
    err = new(_ERR);
    list_prop->set("base_obj",base_obj);
}
//获取object缩写名
string ob_abb_name(object obj)
{
    string ob_name = file_name(obj);
    string *o_name = explode(ob_name,"/");
    return o_name[sizeof(o_name)-1];
}

//添加内容
int add_list_path(object * obj)
{
    string base_o = list_prop->query("base_obj");
    string ob_name;
    foreach(object ob in obj){
        if(inherits(base_o,ob))
            if(!err->repeat_dbase(id_obj,""+ob->id_num()))
            {
                id_obj->set(""+ob->id_num(),ob);
                ob_name = ob_abb_name(ob);
                name_obj->set(ob_name,ob);
            }
    }
}

//添加list 属性
int 

//输入对象名，返回静态对象
object get_object_name(string prop)
{
    if(!err->miss_dbase(name_obj,prop))
        return load_object(name_obj->query(prop));
    else return 0;
}

//输入对象名，返回新建对象
object new_object_name(string prop)
{
    if(!err->miss_dbase(name_obj,prop))
        return new(name_obj->query(prop));
    else return 0;
}

int list_size(){
    return id_obj->dbase_sizeof();
}
