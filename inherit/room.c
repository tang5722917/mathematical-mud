inherit CORE_ROOM;

// 设置环境区域和坐标
varargs void setArea(mixed area, int x, int y, int z, string name)
{
    set("area", area);
    set("zone", ([
        "x":x,
        "y":y,
        "z":z,
        "name":name
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



