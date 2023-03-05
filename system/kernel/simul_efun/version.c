
int version_str_to_int(string version)
{
    string *ver;
    string str="0.1.2";
    debug_message("[" + ctime() + "]世界地图版本: "+version);
    ver = reg_assoc(str, ({"[0-9]+", "[\.]+" }), ({ 1, 2 }), "no-match");

    debug_message("[" + ctime() + "]"+sizeof(ver)+sizeof(ver[0]));
    foreach (string s in ver[0])
        debug_message(s);
    foreach (string s in ver[1])
        debug_message("数据:"+s);

    if(sizeof(ver) ==3)
    {
        //debug_message(ver[0]+ver[1]+ver[2]+"\n");
    }
    return 0;
}   