/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-08 15:23:30
 * @FilePath: \mysticism-mud\inherit\living\status_mystic.c
 * @Description: Living 类中非凡特性接口
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#include <mxp.h>
#include <user.h>
//存储非凡状态对象
nosave protected object * living_mystic = allocate(11);
//存储非凡状态编号
//非凡途径编号*10 + 等级编号
protected mapping living_mystic_id;

// 设置属性值
mixed set_mys(int rank, string mys_ob)
{
    if (!mapp(living_mystic_id))
        living_mystic_id = ([]);
    return living_mystic_id[rank] = mys_ob;
}

// 获取属性值
int query_mys(int rank)
{
    int data;
    data = living_mystic_id[rank];
    return data;
}

//rank 0-9 代表序列0-9， 10表示非序列途径加成
void add_mystic(object mys)
{
    set_mys(mys->mystic_rank(),file_name(mys));
    living_mystic[mys->mystic_rank()]=mys;
}

int delete_mystic(object mys)
{
    int rank = mys->mystic_rank();
    mixed k,mid;
    foreach(k,mid in living_mystic_id)
    {
        if( rank == k)
        {
            living_mystic[k] = 0;
            map_delete(living_mystic_id,k);
            return 1;
        }
    }
    return 0;
}

void update_mystic()
{
    this_object()->update_base_value();
    this_object()->clear_card_ob();
    for(int i=10;i>=0;i--)
    {
        if(living_mystic[i] !=0)
        {
            living_mystic[i]->update_init_value(this_object());
            if(living_mystic[i]->get_card_ob())
                this_object()->add_card_ob(living_mystic[i]->get_card_ob());
        }
    }
}

string living_mystic_name()
{
    for(int i=0;i<=10;i++)
    {
        if(living_mystic[i]!=0)
            return living_mystic[i]->print_mxp_name_all(MYSTIC);
    }
    return find_object(INIT_MYS)->print_mxp_name_all(MYSTIC);
}
