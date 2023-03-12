/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-09 14:35:54
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-03-13 03:15:43
 * @FilePath: \mysticism-mud\inherit\combat_base.c
 * @Description:战斗基类
 *              提供战斗效果/结果的判定框架
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;

//战斗过程信息
protected string *fight_info = ({});

string fight_main_UI(int fight_time,int fight_round){return "";}

//结束战斗
string fight_end()
{
    destruct(this_object());
}

//战斗开始时，第0回合，初始接口
int fight_init(){return 0;}

//战斗过程颜色控制
string * print_color_fig(string * str,int type){return str;}

string print_one_fight()
{
    string str;
    if(sizeof(fight_info) != 0)
    {
        str = fight_info[0];
        fight_info -= ({str});
        return str;
    }
    else return 0;
}