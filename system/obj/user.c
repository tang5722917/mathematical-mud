inherit CORE_USER_OB;

protected mapping user_data;

void create()
{
    seteuid(0); // export_uid
}


// 从游戏中移除这个角色
void remove()
{
    ::remove();
    // todo 玩家存档处理
    save();
    destruct(this_object());
}


// 设置属性值
int set_user(string attr, int value)
{
    return user_data[attr] = value;
}

// 获取属性值
int query_user(string attr)
{
    int data;
    data = user_data[attr];
    return data;
}
