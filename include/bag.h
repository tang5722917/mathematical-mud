/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-08 18:11:40
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-08 18:23:38
 * @FilePath: \mysticism-mud\include\bag.h
 * @Description: 背包、仓库头文件
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#ifndef BAG_H
#define BAG_H

#define STORAGE_POS  class position
#define CARRY_STATUS  class carry_status

class position{
    string room;          //房屋名称
    string furniture;     //家具名
    string room_owner;    //房屋主人
    string owner;         //物品拥有者
}

class carry_status{
    string active;        //是否/装备入对象
    int    active_num;    //装备入对象数量
}

#endif
