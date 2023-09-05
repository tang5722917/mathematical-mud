/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-09-04 11:34:28
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-05 02:35:32
 * @FilePath: \mysticism-mud\inherit\living\gmcp_user.c
 * @Description: GCMP 状态类
 *               记录玩家客户端GCMP状态
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

#define GMCP_LOG 10

nosave string *gmcp_log = ({});
protected mapping gmcp_info;

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
    if()
        debug_message(req);
    log_gmcp("Received: " + req);
}
