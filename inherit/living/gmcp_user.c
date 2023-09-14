/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-09-04 11:34:28
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-11 07:28:57
 * @FilePath: \mysticism-mud\inherit\living\gmcp_user.c
 * @Description: GCMP 状态类
 *               记录玩家客户端GCMP状态
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#define GMCP_LOG 10
#define GMCP_Deal load_object(PATH_DIR "inherit/living/living_d/gmcp_deal_d")
nosave string *gmcp_log = ({});
mapping gmcp_info;

void gmcp_info_init(mapping info)
{
    gmcp_info["client"] = info["client"];
    gmcp_info["gui"] = info["gui"];
    gmcp_info["version"] = info["version"];
    gmcp_info["max_mud_version"]  = info["max_mud_version"];
    gmcp_info["min_mud_version"]  = info["min_mud_version"];
    gmcp_info["enable"] = 0;           //gmcp 判定初始化
}

void set_enable(int enable){
    if(enable)
        gmcp_info["enable"] = 1;
    else gmcp_info["enable"] = 0;
}

int get_gmcp_enable(){
    return gmcp_info["enable"];
}

mapping get_gmcp_info(){
    return gmcp_info;
}

int status_gmcp_enable()
{
    if(( gmcp_info["gui"]=="MYSTICISM_AUTO_TEST") || ( gmcp_info["gui"]=="MYSTICISM_MUD"))
        return 1;
    else return 0;
}

protected int dump_gmcp_log()
{
    write(implode(gmcp_log, "\n") + "\n");
    return 1;
}

private void log_gmcp(string msg)
{
    gmcp_log = gmcp_log[ < GMCP_LOG..] + ({msg});
}

void send_gmcp(string gmcp)
{
    efun::send_gmcp(gmcp);
}

varargs void sendGMCP(mapping data, mixed *modules...)
{
    if (!has_gmcp())
        return;

    if (!mapp(data) || !sizeof(modules))
    {
        return;
    }
    else
    {
        string msg = implode(modules, ".");
        catch (msg += " " + json_encode(data));
        log_gmcp("Sending: " + msg);
        send_gmcp(msg);
    }
}

private void gmcp_enable()
{
    message("system", "GMCP negotiation enabled\n", this_object());
    sendGMCP((["mud_name":MUD_NAME,"mud_version":VERSION]), "Core", "Hello");
    gmcp_info = ([]);
}

void init_gmcp()
{
    if (!has_gmcp())
        return;
    gmcp_enable();
    if (wizardp(this_player()))
    {
        add_action("dump_gmcp_log", "gmcp_log");
    }
}

// gmcp - provides an interface to GMCP data received from the client
void gmcp(string req)
{

    GMCP_Deal->gmcp_deal(req,this_object(),environment());
#ifdef DEBUG_MYSTICISM
    if(DEBUG_GMCP_enable)
        debug_message("[" + ctime() + "] [GMCP]"+ req+" \n");
#endif
    debug_message(req);
    log_gmcp("Received: " + req);
}
