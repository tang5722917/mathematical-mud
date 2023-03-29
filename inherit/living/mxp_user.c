/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-27 19:53:21
 * @FilePath: \mysticism-mud\inherit\mxp.c
 * @Description: MXP 状态类
 *               用于记录客户端MXP返回的信息
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <mxp.h>

private mapping mxp_version_info;
private mapping mxp_support_info;

public void init_mxp() {
 if (!interactive() || !QueryMXP())
        return;
  mxp_version_info = ([]);
  mxp_support_info = ([ MXP_SUPPORT_ENABLED: ({}), MXP_SUPPORT_DISABLED: ({}) ]);
}

public void SetMXPVersion(mapping m) {
  if (!mxp_version_info)
    mxp_version_info = ([]);
  mxp_version_info = m;
}

public void SetEnabledMXPSupportInfo(string *s) {
  if (!mxp_support_info)
    mxp_support_info = ([]);
  mxp_support_info[MXP_SUPPORT_ENABLED] = s;
}

public void SetDisabledMXPSupportInfo(string *s ) {
  if (!mxp_support_info)
    mxp_support_info = ([]);
  mxp_support_info[MXP_SUPPORT_DISABLED] = s;
}

public mapping QueryMXPVersion() {
  return mxp_version_info || ([]);
}

public mapping QueryMXPSupportInfo() {
  return mxp_support_info || ([ MXP_SUPPORT_ENABLED: ({}), MXP_SUPPORT_DISABLED: ({}) ]);
}

int mxp_status()
{
  return 1;
}
