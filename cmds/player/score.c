/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-02-23 10:02:15
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-02-25 05:39:04
 * @FilePath: \mysticism-mud\cmds\player\score.c
 * @Description: 
 * 
 * Copyright (c) 2023 by Donald duck tang5722917@163.com, All Rights Reserved. 
 */
inherit CORE_CLEAN_UP;
#include <ansi.h>


int top_list(string ob1, string ob2)
{
    int score1, score2;
    mapping my = this_player()->query_combat_record("mob");

    score1 = my[ob1];
    score2 = my[ob2];

    return score2 - score1;
}

string score(object me)
{
    string msg;
    mapping my;
    object my_status_value;

    my = me->query_entire_dbase();
    my_status_value = me -> query_status_value();
    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%-34s%-16s| \n", "【" + (my["title"] || "---") + "】" + me->short(),
                   "主要职业：" + chinese(my["vocation"]));
    msg += sprintf(" |%-34s%-16s| \n", " 生日:" + ctime(my["birthday"]), "性别：" + my["gender"]);
    msg += sprintf(" |%-50s| \n", "");
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-25s%-25s| \n", "血气：" + my_status_value->query_attr("hp") + " / " + my_status_value->query_attr("max_hp"), "精力：" + my_status_value->query_attr("mp") + " / " + my_status_value->query_attr("max_mp") );
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "力量：" + my_status_value->query_attr("str"), "敏捷：" + my_status_value->query_attr("agi"),"灵性：" + my_status_value->query_attr("sen"));
    msg += sprintf(" |%-15s%-15s%-20s| \n", "理性：" + my_status_value->query_attr("int"), "疯狂：" + my_status_value->query_attr("cra"), "幸运：" + my_status_value->query_attr("luk"));
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-30s%-20s| \n", "对战(胜/败/平):" + my["exp_win"]+" / "+ my["exp_fal"] +" / "+ my["exp_equ"], "世界等级：" + my["wlv"]);
    msg += sprintf(" |%-30s%-20s| \n", "金钱：" + my["coin"], "银行存款：" + my["exp"]);
    msg += sprintf(" |%-50s| \n", "");

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += YEL "  提示：使用 score -s 查看个人状态。\n" NOR;
    return msg;
}

string score_hp(object me)
{
    string msg, hpbar, mpbar, status = "";
    mapping condition;
    object *team;

    // 组队状态
    if (sizeof(team = me->query_team()) > 1)
    {
        msg = "*队伍成员状态*\n";
        foreach(object member in team)
        {
            hpbar = graph_draw(member->query_hp(),member->query_max_hp(), 2, 1, 10);
            mpbar = graph_draw(member->query_mp(),member->query_max_mp(), 4, 7, 10);
            msg += sprintf(HIM "%-20s" HIG "HP：%-15s\t" HIB "MP：%s\n" NOR,member->short(), hpbar, mpbar);
        }
    }
    else
    {
        if (mapp(condition = me->query("condition")))
        {
            foreach (string key, mapping value in condition)
            {
                status += replace_string(key, "#", "/")->query_condition_name() + "  ";
            }
        }

        hpbar = graph_draw(me->query_hp(),me->query_max_hp(), 2, 1, 10);
        mpbar = graph_draw(me->query_mp(),me->query_max_mp(), 4, 7, 10);
        msg = sprintf(HIG "HP：%s\t" HIB "MP：%s" NOR, hpbar, mpbar);
        msg += "\n------------------------------------------------------\n";
        msg += sprintf("状态：%s\n", status);
    }

    return msg;
}

int main(object me, string arg)
{
    string msg;

    switch (arg)
    {
    case "-s":
        msg = score_hp(me);
        break;

    default:
        msg = score(me);
    }
    write(msg);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : score [-s]

这个指令可以让你查看个人档案资料。

HELP );
    return 1;
}