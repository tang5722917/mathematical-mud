/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-10 16:04:34
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-14 14:35:00
 * @FilePath: \mysticism-mud\test\test_inherit\test_dbase_data.c
 * @Description:  提供data修改方法
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

int test_change_dbase_data(object me,string prop,mixed value)
{
    if(me->definedp(prop)){
        me->set(prop,value);
        return 1;
    }
    return 0;
}

varargs int test_change_room_data(object me,string room,string last_room)
{
    test_change_dbase_data(me,"space_room",room);
    if(stringp(last_room))
        test_change_dbase_data(me,"next_space_room",last_room);
    else test_change_dbase_data(me,"next_space_room","");
}
