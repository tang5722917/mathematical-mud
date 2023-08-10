/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-28 19:24:18
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-10 19:04:04
 * @FilePath: \mysticism-mud\test\test_inherit\test_base.c
 * @Description: test_data 基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit CORE_CLEAN_UP;
inherit PATH_DIR "test/test_inherit/test_data";

init_data(object me){
    update_data(me);
}

void test_main(object me)
{
    write("载入"+file_name()+"测试数据");
    init_data(me);
}
