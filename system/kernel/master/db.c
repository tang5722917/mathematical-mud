/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-04-12 18:10:48
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-13 14:02:39
 * @FilePath: \mysticism-mud\system\kernel\master\db.c
 * @Description: 数据库初始化函数
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 int init_sqlite3()
 {
    object ob,db;
    string db_host,str, *s;
    mixed db_db,rows,*f,db_handle;
    mapping db_config=([]);
    ob = find_object(CORE_ENV_D);
    db = load_object(DB_D);
    if(db == 0)
    {
        debug_message("[" + ctime() + "]数据库初始化失败");
        return 0;
    }
    if(MYSTICISM_DB == 0)
    {
        debug_message("[" + ctime() + "]当前PATH游戏配置不支持数据库功能");
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
            debug_message("[" + ctime() + "]数据库连接失败：" + db);
        else
            debug_message("[" + ctime() + "]数据库连接成功：" + db);
    }
    debug_message("[" + ctime() + "]数据库状态：" + db_status());
    db_handle=db->get_db_handle();
    rows = db_exec(db_handle,"select * from DB_Info;");
    f = db_fetch(db_handle,1);
    debug_message("[" + ctime() + "]Mysticism-MUD数据库版本：" + f[0]);
    debug_message("[" + ctime() + "]Mysticism-MUD数据库版本说明:" + f[1]);
}
