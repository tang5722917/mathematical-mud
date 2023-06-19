/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-12 18:10:48
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-06-20 04:12:22
 * @FilePath: \mysticism-mud\system\kernel\master\sys_d.c
 * @Description: 游戏服务进程初始化
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#define MUDLIST_SERVER "118.190.104.241"
#define MUDLIST_SERVER_PORT 5567
#define INTERMUD_MUD_NAME "MYSTICISM-MUD"
#define __PORT__ 2023
#define MUDLIB_NAME "诡秘世界"

 int init_sql_sys_db()
 {
    object ob,db;
    mixed db_db,rows,*f,db_handle;
    mapping db_config=([]);
    ob = find_object(CORE_ENV_D);
    db = load_object(MYSTICISM_SYS_DB_D);
    if(db == 0)
    {
        debug_message("[" + ctime() + "]数据库初始化失败");
        return 0;
    }
    if((MYSTICISM_DB == 0) || (ob->query("DB_enable") !=1))
    {
        debug_message("[" + ctime() + "]当前游戏配置不支持数据库功能");
        return 0;
    }
    debug_message("[" + ctime() + "]当前游戏数据类型："+ob->query("DB_TYPE"));
    debug_message("[" + ctime() + "]当前游戏数据库名："+ob->query("DB_DATABASE"));
    if(ob->query("DB_TYPE") == "SQLite")
    {
        debug_message("[" + ctime() + "]当前游戏数据库路径："+ob->query("DB_PATH"));
        db_db = ob->query("DB_PATH")+ob->query("DB_DATABASE")+".db";
        db_config["host"]="";
        db_config["database"]=db_db;
        db_config["user"]="";
        db_config["type"]=__USE_SQLITE3__;
        db->setConnection(db_config);
        db->exec();
        if (stringp(db)) /* error */
        {
            debug_message("[" + ctime() + "]数据库连接失败：" + db);
            return 0;
        }
        else
            debug_message("[" + ctime() + "]数据库连接成功：" + db);
    }
    db_handle=db->get_db_handle();
    rows = db_exec(db_handle,"select * from DB_Info;");
    if (!rows)
    {
        debug_message("[" + ctime() + "]数据库状态错误" );
    }
    else if (stringp(rows))
    {
        debug_message("[" + ctime() + "]数据库状态错误："+ rows );
    }
    else{
        f = db_fetch(db_handle,1);
        db->close();
        debug_message("[" + ctime() + "]Mysticism-MUD数据库版本：" + f[0]);
        debug_message("[" + ctime() + "]Mysticism-MUD数据库版本说明:" + f[1]);
        return 1;
    }
}

int init_sys_d()
{
    object ob;
    load_object(CORE_ENV_D);
    debug_message("[" + ctime() + "]游戏env文件成功导入");
    load_object(CORE_INTERMUD_D);
    //时间初始化
    ob = load_object(TIME_D);
    ob->set_scale(1,0,1);
    ob->reset_gametime(find_object(TIME_D)->query_realtime());
    ob->process_gametime(ob->query_gametime());
    init_sql_sys_db();
    //天气初始化
    ob = load_object(NATURE_D);
    ob->event_midnight();
}
