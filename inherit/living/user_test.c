/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2024-01-08 11:26:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-08 13:39:09
 * @FilePath: \mysticism-mud\inherit\living\user_test.c
 * @Description:  实现玩家对象测试功能
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#include <test.h>

int restore_save(string arg)
{
    string file;
    object user;
    if (stringp(file = TEST_SAVD_DATA + "autotest_"+arg)){
        write(arg+":"+file);
        if(!restore_object(file))
            return 0;
        user = this_object();
        user->move(user->query("space_room"));
        return 1;
    }
    return 0;
}
