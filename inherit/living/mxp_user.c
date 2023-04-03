/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-03 13:28:53
 * @FilePath: \mysticism-mud\inherit\living\mxp_user.c
 * @Description: MXP 状态类
 *               用于记录客户端MXP返回的信息
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <mxp.h>
#include <ansi.h>

protected int mxp_enable;

protected mapping mxp_version_info;
protected mapping mxp_support_info;

void MXP_test_init()
{
  send_MXP("VERSION");
}

void MXP_support_init()
{
  send_MXP("SUPPORT");

}

public void SetMXPVersion(string s) {
    if (!mxp_version_info)
        mxp_version_info = ([]);
    mxp_version_info[1] = s;
    MXP_support_init();
}

public void SetMXPSupportInfo(string s) {
  if (!mxp_support_info)
    mxp_support_info = ([]);
  mxp_support_info[1] = s;
}

public mapping QueryMXPVersion() {
  return mxp_version_info ||  ({});
}

public mapping QueryMXPSupportInfo() {
  return mxp_support_info ||  ({});
}

int mxp_status()
{
  return 1;
}

void MXP_info_get(string arg)
{

}

void set_mxp_enable(int status)
{
    mxp_enable = status;
}

int get_mxp_enable()
{
    return mxp_enable;
}
