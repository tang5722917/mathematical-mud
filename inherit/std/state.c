/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-29 15:37:07
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-29 17:34:33
 * @FilePath: \mysticism-mud\inherit\std\state.c
 * @Description:  有限状态机基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

nosave protected object dbase;
nosave protected int state_num;   //状态编号
//num  状态编号  str 状态名  ob1/ob2/ob3
varargs void init(int num,string str){
    dbase = new(_DBASE);
    state_num = num;
    if(stringp(str))
        dbase->set("state_str",str);
}
//判断是否是本状态
int is_state(int num){return (num == state_num);}

int get_state_num(){return state_num;}
string get_state_str(){return dbase->query("state_str");}

mixed state_query(mixed key){return dbase->query(key);}
mixed state_set(mixed key,mixed value){return dbase->set(key,value);}

varargs void enter_state_do(object ob,object user){} //进入该状态时的行为
