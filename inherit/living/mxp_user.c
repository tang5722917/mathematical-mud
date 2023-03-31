/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-31 14:13:11
 * @FilePath: \mysticism-mud\inherit\living\mxp_user.c
 * @Description: MXP 状态类
 *               用于记录客户端MXP返回的信息
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <mxp.h>
#include <msp.h>
#include <ansi.h>

protected mapping mxp_version_info;
protected mapping mxp_support_info;

void MXP_test_init()
{
    MXP_write("<VERSION>");
}

void MXP_support_init()
{
    MXP_write("<SUPPORT>");

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
