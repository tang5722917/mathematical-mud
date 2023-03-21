/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 18:11:41
 * @FilePath: \mysticism-mud\inherit\living\status_mystic.c
 * @Description: Living 类中非凡特性接口
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

//存储非凡状态对象
nosave protected object * living_mystic = allocate(11);
//存储非凡状态编号
//非凡途径编号*10 + 等级编号
protected mapping living_mystic_id;

// 设置属性值
int set_mys(int rank, int mys)
{
    if (!mapp(living_mystic_id))
        living_mystic_id = ([]);
    return living_mystic_id[rank] = mys;
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
    set_mys(mys->rank_num(),mys->mystic_id());
    living_mystic[mys->rank_num()]=mys;
}

void update_mystic()
{
    for(int i=10;i>=0;i--)
    {
        if(living_mystic[i] !=0)
        {
            living_mystic[i]->update_init_value(this_object());
        }
    }
}