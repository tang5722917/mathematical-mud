/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-09 14:19:03
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-09 14:59:45
 * @FilePath: \mysticism-mud\World\include\attack.h
 * @Description: 定义攻击类型
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#ifndef ATTACK_H
#define ATTACK_H

#define A_WATER   1  //水属性
#define A_WIND    2  //风属性
#define A_FIRE    3  //火属性

//base 基础攻击参数    hit 基础命中率       property  攻击属性
//type 单体/范围攻击  1为单体， 大于1的数表示攻击最大目标数
#define ATTACK_P class attack_p
class attack_p{
    float base;
    int hit;
    int property;
    int type;
}

#define A_VALUE class attack_value
class value {
    int hp;
    int mp;
    int str;
    int agi;
    int sen;
    int intt;
    int cra;
    int luk;
    int mys;
}
A_VALUE get_living_value(int hp,int mp,int str,int agi,int sen,int intt,int cra,int luk,int mys)
{
    return new(A_VALUE,hp:hp,mp:mp,str:str,agi:agi,sen:sen,intt:intt,cra:cra,luk:luk,mys:mys);
}
#endif  //ATTACK_H
