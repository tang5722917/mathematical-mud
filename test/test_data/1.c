/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-06-28 17:56:09
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-15 13:57:03
 * @FilePath: \mysticism-mud\test\test_data\1.c
 * @Description:  新手出生任务测试
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit _TEST_DATA;

init_data(object me){
    test_change_room_data(me,"/World/00/start_room");
    
    update_data(me);
}
