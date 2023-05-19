/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-17 19:45:39
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-19 19:34:11
 * @FilePath: \mysticism-mud\inherit\task\task_action\task_choice.c
 * @Description:  用于实现任务中的选项动作
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>

nosave protected mixed *task_ch; //确认队列
nosave protected string choice_info;  //choice title
nosave protected object user;   //确认的user
nosave protected int ch_n;
nosave protected mixed *choice_result;
nosave protected function do_confirm;
void init(object u)
{
    user = u;
    choice_info = "";
    task_ch = ({});
    ch_n = 0;
    choice_result = ({});
}

void do_confirm_choice(function f)
{
    do_confirm = f;
}

void add_choice_title_info(string str){
    choice_info = str;
}

void add_choice(mixed *ch){
    task_ch += ({ch});
}

string print_choice_info()
{
    string str;
    mixed *c;
    str = choice_info;
    str += "---------------------------------\n";
    c = task_ch[0];
    str += c[0];
    for(int i=1 ;i<sizeof(c);i++)
        str += c[i][0];
    str += "---------------------------------";
    return str;
}

//否定确认后重新确认
void choice_confirm_no()
{
    ch_n = 0;
    choice_result = ({});
    message("CHI",HBRED "你不接受之前的选择，请重新选择" NOR,user);
    message("CHI",print_choice_info(),user);
}

string confirm_info()
{
    string str="";
    foreach(mixed *c in choice_result)
    {
        str += c[0];
    }
    return str;
}

//选择确认
void choice_confirm_info()
{
    string str;
    str  = "----------------------------\n";
    str += "请确认你的选择，输入Y（y）表示确认\n";
    str += "你的选择为：\n";
    str += confirm_info();
    str += "----------------------------";
    message("CHI",str,user);
}

//在确认阶段选择非y/Y
int is_choice_confirm()
{
    if(ch_n == sizeof(task_ch))
    {
        choice_confirm_no();
        return 1;
    }
    return 0;
}

int is_confirm(){return (ch_n == sizeof(task_ch));}

int choice_item(int n)
{
    string str;
    mixed *c ;
    if(ch_n < sizeof(task_ch)){
        c = task_ch[ch_n];
        for(int i=1 ;i<sizeof(c);i++)
            if(n == c[i][1])
            {
                choice_result += ({({c[i][0],n})});
                str = "\n你选择了：" + c[i][0];
                message("CHI",str,user);
                return 1;
            }
        message("CHI",HBRED "你输入的数字不符合选项" NOR,user);
        return 0;
    }
    else choice_confirm_no();
    return 0;
}

void choice_item_again()
{
    string str="";
    mixed *c;
    str += "---------------------------------\n";
    c = task_ch[ch_n];
    str += c[0];
    for(int i=1 ;i<sizeof(c);i++)
        str += c[i][0];
    str += "---------------------------------";
    message("CHI",str,user);
}

void choice_next_item()
{
    ch_n += 1;
    if(ch_n < sizeof(task_ch))
        choice_item_again();
    else{
        message("CHI","成功完成选择，请确认选项：",user);
        choice_confirm_info();
    }
}

void task_confirm()
{
    evaluate(do_confirm,choice_result,user);
    message("CHI",HBGRN "成功完成选择确认" NOR,user);
    user->set_choice_command(0);
    destruct();
}

void start(){
    message("CHI",print_choice_info(),user);
    user->task_choice_start(this_object());
}
