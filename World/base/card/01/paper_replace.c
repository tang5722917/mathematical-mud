/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-22 11:06:06
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 08:33:37
 * @FilePath: /mysticism-mud/World/base/card/01/paper_replace.c
 * @Description:  纸人替身牌
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#include <card.h>

string card_name(){return "纸人替身";}
string card_short(){return "放置一个生命为1的纸人，抵挡一次攻击";}
//1-card 01-对应非凡途径序号1占卜家 7-魔术师 01编号
int card_id(){return 101701;}

//效果类型： 单体召唤
int *perform_type(){return ({CSUMMON});}
//战斗效果说明：
string card_effect_descript(){return "一个血量为1的纸人";}
//效果执行
object * perform_summon()
{
    object ob = load_object(MYSTIC_SUMMON "01/paper_replace");
    return ({ob});
}
