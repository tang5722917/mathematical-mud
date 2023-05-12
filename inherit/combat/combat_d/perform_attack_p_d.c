/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-09 02:46:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-12 17:10:48
 * @FilePath: \mysticism-mud\inherit\combat\combat_d\perform_attack_p_d.c
 * @Description: 处理物理攻击效果
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <attack.h>
#include <combat.h>
#include <ansi.h>
string attack_effect(object user , object target,ATTACK_P p,object card_ob)
{
    string s="";
    int damage;
    if(load_object(ATTACK_HIT)-> perform_attack_hit(user,target,p,card_ob))
    {
        if(p->type % 2)
            damage = to_int(user-> query_attr("str") * p->base) + p->fix;
        else
            damage = to_int(user-> query_attr("sen") * p->base) + p->fix;
        target-> query_sub_attr("hp",damage);
        s +=WHT + card_ob->card_name() + "造成伤害："+ damage + NOR "\n";
        return s;
    }
    else
    {
        s +=GRN+ card_ob->card_name() +  "未命中目标" + NOR "\n";
        return s;
    }
}

 string attack_p(object *user,object card_ob,object combat)
 {
    string str = "";
    mapping card_m = card_ob->perform_attack1();
    if(sizeof(user) == 2)
    {
        str += card_ob->card_effect_descript();
        str +="\n"+load_object(ATTACK_LOSS)->attack_loss(user[0],card_m["attack_loss"],card_ob);
        str += attack_effect(user[0],user[1], card_m["attack_base"],card_ob);
    }
    else{}   //群体物理伤害
    return str;
 }
