/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-14 14:06:57
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-14 14:36:38
 * @FilePath: \mysticism-mud\test\test_inherit\test_port_fun.c
 * @Description: 客户端接口具体实现
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit _TEST_DATA;
void fun_dbase(object me,string prop,mixed value)
{
    if(!test_change_dbase_data(me,prop,value))
        write("dbase 操作错误\n");
}

void fun_update(object me)
{
    update_data(me);
}
