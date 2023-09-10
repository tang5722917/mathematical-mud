/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-09-06 00:12:36
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-06 00:15:53
 * @FilePath: \mysticism-mud\system\kernel\simul_efun\debug.c
 * @Description: 提供一些debug函数 
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

void debug_msg(object user,mixed s){
    message("Debug",sprintf("%O",s),user);
}
