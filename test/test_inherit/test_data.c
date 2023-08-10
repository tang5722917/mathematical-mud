/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-10 18:38:22
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-10 19:03:48
 * @FilePath: \mysticism-mud\test\test_inherit\test_data.c
 * @Description: 提供data修改方法
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
 inherit PATH_DIR "test/test_inherit/test_dbase_data";

void update_data(object me){
    me->save();
    me->move(me->query("space_room"));
}
