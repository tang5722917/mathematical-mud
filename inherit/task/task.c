/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-03-04 18:04:36
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-23 11:23:58
 * @FilePath: \mysticism-mud\inherit\task\task.c
 * @Description: 游戏任务基本类
 * Copyright (c) 2023 by tang5722917@163.com, All Rights Reserved. 
 */
#include <task.h>
inherit CORE_STD_TEST;
inherit _DBASE;
//设置任务类型
//WORLD    1
//BORN     2
//ORG      3
//MYSTIC   4
//SKILL    5
void set_task_type(int type){
    set("task_type", type);
}
int query_task_type(){
    return query("task_type");
}
//设置详细的任务类型
void set_task_subtype(mixed subtype){
    set("task_subtype", subtype);
}
mixed query_task_type(){
    return query("task_subtype");
}
