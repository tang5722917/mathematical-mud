
int version_str_to_int(string version)
{
    string *ver;
    int ver_num;
    ver =  explode(version,".");
    if (sizeof(ver) != 3 )
        return 0;
    ver_num = to_int(ver[2])+(to_int(ver[1])*1000)+(to_int(ver[0])*1000000);
    debug_message("[" + ctime() + "]世界地图版本: "+version+" : "+ ver_num);
    return ver_num;
}   