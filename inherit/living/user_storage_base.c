/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-07-03 16:14:13
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-10 15:45:11
 * @FilePath: \mysticism-mud\inherit\living\user_storage_base.c
 * @Description: 个人物品存储 基类 - 存档数据结构
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


#include <bag.h>
#define MAX_SIZE_BASE_BAG  100
//每个元素：{string obj, int num}
//每个仓库：{class position, 元素1, ...}
mixed *user_storage;  // 仓库
//每个元素：{string obj, int num, class carry_status}
mixed *user_bag;      //玩家携带

void bag_storage_init()
{
    if(!arrayp(user_storage))
        user_storage = ({});
    if(!arrayp(user_bag))
        user_bag = ({
            ({"base_bag"}),
            ({""}),
            ({""}),
            ({""}),
            ({""})
        });   //背包由基本背包+4个附加容器构成
}

STORAGE_POS get_position(string room,string furniture,string room_owner,string owner){
    return new(STORAGE_POS, room:room,furniture:furniture,room_owner:room_owner,owner:owner);
}

mixed * storage_item(string obj, int num){
    mixed * item=({obj,num});
    return item;
}

void add_storage_repository(STORAGE_POS pos){
    mixed * repository_item = ({pos});
    user_storage += ({repository_item});
}

int equal_position(STORAGE_POS pos1,STORAGE_POS pos2)
{
    if(pos1->room != pos2->room)
        return 0;
    if(pos1->furniture != pos2->furniture)
        return 0;
    if(pos1->room_owner != pos2->room_owner)
        return 0;
    if(pos1->owner != pos2->owner)
        return 0;
    return 1;
}

int equal_user_position(STORAGE_POS pos1,STORAGE_POS pos2)
{
    if(pos1->room != pos2->room)
        return 0;
    if(pos1->furniture != pos2->furniture)
        return 0;
    return 1;
}

int size_repository(STORAGE_POS repository){
    int size=0;
    foreach(mixed *repo_temp in user_storage){
        if(equal_user_position(repository,repo_temp[0])){
            for(int i=1;i<sizeof(repo_temp);i++)
                size += load_object(repo_temp[i][0])->storage_space() * repo_temp[i][1];
            return size;
        }
    }
    return -1;
}

CARRY_STATUS get_carry_status(string active,int active_num){
    return new(CARRY_STATUS,active:active,active_num:active_num);
}

mixed * carry_item(string obj, int num,CARRY_STATUS status){
    mixed * item=({obj,num,status});
    return item;
}

int size_bag(int n){
    int size=0;
    if(n <0 || n > 5)
        return -1;
    if(sizeof(user_bag[n]) == 1)
        return 0;
    else{
        for(int i=1;i<sizeof(user_bag[n]);i++){
            size += load_object(user_bag[n][i][0])->storage_space() * user_bag[n][i][1];
        }
        return size;
    }
}

string add_bag_item(int bag_num,mixed * carry_item)
{
    if(bag_num == 0)
    {
        if(size_bag(0) > MAX_SIZE_BASE_BAG)
            return "该背包的空间已满";
        return 0;
    }
    else{
        return 0;
    }
}
