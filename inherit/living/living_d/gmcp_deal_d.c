/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-09-05 23:03:27
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-09-06 00:27:45
 * @FilePath: \mysticism-mud\inherit\living\living_d\gmcp_deal_d.c
 * @Description:  接收到的GMCP 指令处理
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

object gmcp_var_decode(string var)
{
    string var_main;
    object deal_ob;
    string * vars = explode(var, "." );
    if(!sizeof(vars))
        return 0;
    var_main = vars[0];
    if(!stringp(var_main))
        return 0;
    switch(var_main)
    {
        case "Client" :
            deal_ob = load_object(PATH_DIR "inherit/living/living_d/gmcp_client_ob");
            break;
        default: deal_ob = 0;
    }
    return deal_ob;
}

int gmcp_deal(string req,object user,object env)
{
    mixed *gmcp_req;
    string text;
    string var = explode( req, " " )[0];
    object deal_ob;
    text = req[strlen(var)+1..];
    gmcp_req = json_decode(text);
    if(sizeof(gmcp_req))
    {
        deal_ob = gmcp_var_decode(var);
        if(! objectp(deal_ob)){
            debug_message("[" + ctime() + "] [GMCP Instruction ERROR] "+ req+" \n");
            return 0;
        }
        deal_ob->gmcp_deal(user,var,gmcp_req,env);
        return 1;
    }
    else 
        debug_message("[" + ctime() + "] [GMCP ERROR] "+ req+" \n");
        return 0;
}
