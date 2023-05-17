/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 02:24:53
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-17 17:09:50
 * @FilePath: \mysticism-mud\inherit\living\living_d\user_input_num_d.c
 * @Description:玩家输入数字处理
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <user.h>

int user_input_number( object me, object env ,int in_num )
{
    write("你输入的选项数字为:" + in_num);
    me->set_choice_command(0);
    return 1;
}

int user_choice_confirm(object me,object env)
{
    me->set_choice_command(0);
    return 0;
}
