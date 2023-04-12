inherit CORE_MASTER_OB;
// 玩家连线入口方法，返回连线对象
#include "master/parser.c"
#include "master/db.c"
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
    load_object(CORE_ENV_D);
    debug_message("[" + ctime() + "]游戏env文件成功导入");
    preload(TIME_D);
    find_object(TIME_D)->set_scale(1,0,1);
    find_object(TIME_D)->reset_gametime(find_object(TIME_D)->query_realtime());
    preload(SYSTEM_OBJ);
    preload(Game_World);
    init_sqlite3();
}

// driver 启动测试
void flag(string str)
{
    debug_message("[" + ctime() + "]"+str+"\n");
    switch (str)
    {
    case "debug":
        store_variable("DEBUG", 1);
        break;
    case "auto-test":
        
        break;
    default:
        write("[CORE_MASTER_OB]->flag():The only supproted flag is 'debug', got '" + str + "'.\n");
    }
}

//MSSP 数据
mapping get_mud_stats(void)
{
    mapping mssp=([]);
    mssp["MXP"]="1";
    mssp["MSP"]="1";
    mssp["MSDP"] = "0";
    mssp["MCP"] = "0";
    mssp["GMCP"] = "1";
    mssp["MCCP"] = "0";
    mssp["LANGUAGE"] = "Chinese";
    mssp["LOCATION"] = "China";
    return mssp;
}
