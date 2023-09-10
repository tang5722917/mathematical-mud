/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-29 16:13:08
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-09 03:44:42
 * @FilePath: \mysticism-mud\system\obj\pre_object.c
 * @Description: 预加载的系统Obect
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 inherit CORE_STD_PRE;
 
 string ob_name()
 {
     return "系统";
 }

 void create()
 {
    ::create();
     add_obj("/system/obj/start_mxp","start_mxp");
     add_obj("/system/obj/start_gmcp","start_gmcp");
     load_path_object(INHERIT_PATH "combat/combat_d/");
     ob_load_end(sizeof(obj));
 } 
