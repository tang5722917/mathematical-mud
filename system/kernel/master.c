inherit CORE_MASTER_OB;

// 玩家连线入口方法，返回连线对象
private object connect(int port)
{
    object login_ob;
    mixed err;

    err = catch (login_ob = new(MYSTICISM_LOGIN_OB));
    if (err)
    {
        write("服务器维护中，请稍候……\n");
        destruct(this_object());
    }
    return login_ob;
}

private void create()
{
    debug_message("[" + ctime() + "]CORE_MASTER_OB->create()!");
    preload(Game_World);
}
