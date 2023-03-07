/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-03 18:22:14
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-07 17:16:20
 * @FilePath: \mysticism-mud\inherit\room.c
 * @Description: 房间基类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */
inherit CORE_ROOM;
inherit CORE_STD_TEST;
protected int room_type=0;

// 设置环境区域和坐标
varargs void setArea(mixed area, int x, int y, int z, string name)
{
    set("area", area);
    set("zone", ([
        "x":x,
        "y":y,
        "z":z,
        "name":name,
        "visible":1
    ]));
}

varargs void set_area(mixed area, int x, int y, int z, string name)
{
    setArea(area, x, y, z, name);
}

// 获取区域坐标
string coordinate()
{
    mapping coordinate = query("zone");
    int x, y, z;
    string name;
    if (!mapp(coordinate))
        coordinate = ([]);
    x = coordinate["x"];
    y = coordinate["y"];
    z = coordinate["z"];
    name = coordinate["name"];
    return sprintf("(%d,%d,%d,%s)", x, y, z, name);
}

// 获取区域名称
string Room_name()
{
    mapping coordinate = query("zone");
    string name;
    if (!mapp(coordinate))
        coordinate = ([]);
    name = coordinate["name"];
    return sprintf("(%s)", name);
}

int get_room_type()
{
    return room_type;
}

int obs_num_in_room()
{
    mapping obs;
    obs = query_temp("objects");
    return sizeof(obs);
}

object ob_in_room(string id)
{
    mapping obs;
    obs = query_temp("objects");
    foreach (string key,object ob in obs)
    {
        if (id == ob->query("id"))
            return ob;
    }
    return 0;
}



