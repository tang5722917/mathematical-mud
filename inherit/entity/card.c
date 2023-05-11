/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-27 15:24:00
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-11 20:43:01
 * @FilePath: \mysticism-mud\inherit\entity\card.c
 * @Description: 卡牌实现基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
inherit INHERIT_PATH "entity/entity";

#include <ansi.h>
#include <attack.h>
//卡牌名称
string card_name(){return "";}
//卡牌short 介绍
string card_short(){return "";}
//卡牌id
int card_id(){return 10;}
//Card 战斗效果说明
string card_effect_descript(){return "";}
string print_card_name(object user){return print_mxp_name(2,user);}

int entity_id(){return card_id();}
string mxp_name(){return card_name();}
string mxp_explain(){return card_short();}

//Card 执行相关接口
int *perform_type(){return 0;}
//Card 详细说明
string *perform_type_str(){return 0;}

A_VALUE put_card_loss_mp(int mp)
{
    return get_living_value(0,mp,0,0,0,0,0,0,0);
}

object * perform_buff1(){return 0;}   //给予己方状态BUFF
object * perform_buff2(){return 0;}   //给予对方状态BUFF
object * perform_summon(){return 0;}  //召唤物品

mapping perform_attack1(){return 0;}  //完成物理HP攻击
//完成物理HP攻击  
//注，所有带有火/水/风/格斗等属性的攻击都属于物理ming攻击。
//base 基础攻击参数    hit 基础命中率       property  攻击属性
//type 单体/范围攻击  1为单体， 大于1的数表示攻击最大目标数
//attack_type1 最基础的攻击类型，消耗mp
mapping  attack_type1(float base,int hit,int property,int type,int mp ) 
{
    mapping m = ([]);
    m["attack_base"] = new(ATTACK_P,base:base,hit:hit,property:property,type:type);
    m["attack_loss"] = put_card_loss_mp(mp);
    return m;
}
//完成非凡HP攻击  
//注，没有物理属性的攻击，如诅咒/生命偷窃等。
mapping  perform_attack2(){return 0;}  //完成非凡HP攻击
mapping  perform_value1(){return 0;}  //对己方的属性进行改变
mapping  perform_value2(){return 0;}   //对对方的属性进行改变

string *get_perform_type()
{
    string s,str;
    string *s_result;
    int *perform_q = perform_type();
    string *s_type = perform_type_str();
    s_result = ({});
    foreach(int i in perform_q){
        s = "";
        if( i/7 == 0)
        {
            str = "单体技能";
        }
        else
        {
            str = "群体技能 最大目标数："+ i/7;
        }
        switch(i%7)
        {
            case 1:
                s += "己方BUFF "+str ;
                break;
            case 2:
                s += "敌方BUFF "+str;
                break;
            case 3:
                s += "召唤 "+str;
                break;
            case 4:
                s += "物理攻击 "+str;
                break;
            case 5:
                s += "非凡攻击 "+str;
                break;
            case 6:
                s += "己方属性 "+str;
                break;
            case 7:
                s += "敌方属性 "+str;
                break;
            default:
                break;
        }
        s += "\n";
        s += s_type[i];
        s_result +=({s});
    }
    return s_result;
}
