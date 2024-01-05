/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-14 12:44:05
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-05 19:11:09
 * @FilePath: \mysticism-mud\test\test_inherit\test_port.c
 * @Description: test 对客户端接口
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

inherit PATH_DIR "test/test_inherit/test_port_fun";
//指令列表
private mapping test_port_ins=([
    "dbase":2,
    "update":0,
    "load":1,
]);

//检查输入指令/参数数量是否正确是否正确
int check_ins(string arg,int num)
{
    if(!undefinedp(test_port_ins[arg]))
    {
        if(num == test_port_ins[arg])
            return 1;
        else return 0;
    }
    else return 0;
}
//执行指令
int perform(string * arg,object me)
{
    int arg_num = test_port_ins[arg[0]];
    switch(arg_num)
    {
        case 0:
            return call_other(this_object(),"fun_"+arg[0],me);
        case 1:
            return call_other(this_object(),"fun_"+arg[0],me,arg[1]);
        case 2:
            return call_other(this_object(),"fun_"+arg[0],me,arg[1],arg[2]);           
    }
}
