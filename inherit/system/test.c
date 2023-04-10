/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-07 09:58:44
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-07 10:21:09
 * @FilePath: \mysticism-mud\inherit\test.c
 * @Description: 测试基类，提供自测试接口 
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
//具体的测试方法
 void test_object (object auto_test)
 {
    ;
 }


 //公共的测试接口
int test(object auto_test)
{
    this_object()->create();
    test_object (auto_test);
    destruct(this_object());
    return 1;
}