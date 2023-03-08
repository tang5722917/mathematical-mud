/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-08 18:05:06
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-08 18:11:28
 * @FilePath: \mysticism-mud\inherit\combat.c
 * @Description:  战斗基类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

inherit CORE_CLEAN_UP;
#include <ansi.h>

nosave protected object * obs1=({});
nosave protected object * obs2=({});

void create()
{
    ;
}

string fight_main(object me)
{
    string msg;
    mapping my;

    my = me->query_entire_dbase();

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%-34s%-16s| \n", "【" + (my["title"] || "---") + "】" + me->short(),
                   "主要职业：" + chinese(my["vocation"]));
    msg += sprintf(" |%-34s%-16s| \n", " 生日:" + ctime(my["birthday"]), "性别：" + my["gender"]);
    msg += sprintf(" |%-50s| \n", "");
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-25s%-25s| \n", "血气：" + me->query_attr("hp") + " / " + me->query_attr("max_hp"), "精力：" + me->query_attr("mp") + " / " + me->query_attr("max_mp") );
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "力量：" + me->query_attr("str"), "敏捷：" + me->query_attr("agi"),"灵性：" + me->query_attr("sen"));
    msg += sprintf(" |%-15s%-15s%-20s| \n", "理性：" + me->query_attr("int"), "疯狂：" + me->query_attr("cra"), "幸运：" + me->query_attr("luk"));
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-30s%-20s| \n", "对战(胜/败/平):" + my["exp_win"]+" / "+ my["exp_fal"] +" / "+ my["exp_equ"], "世界等级：" + my["wlv"]);
    msg += sprintf(" |%-30s%-20s| \n", "金钱：" + my["coin"], "银行存款：" + my["exp"]);
    msg += sprintf(" |%-50s| \n", "");

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += YEL "  提示：使用 score -s 查看简略状态。\n" NOR;
    msg += YEL "  提示：使用 score -a 查看详细个人状况。\n" NOR;
    return msg;
}