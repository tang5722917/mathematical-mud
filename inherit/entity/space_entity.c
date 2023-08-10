/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-08-09 20:09:12
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-08-10 14:01:48
 * @FilePath: \mysticism-mud\inherit\entity\space_entity.c
 * @Description:  实体的存储特性基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
//返回物品占用存储空间，最小单位为1
int storage_space(){
    return 1;
}

// 物品显示时是否可以堆叠
int is_overlap(){
    return 1
}

// 物品存放要求
// 0 普通室内环境
// 1 灵性密封环境
// 2 特殊封印环境
int storage_env(){
    return 0;
}
