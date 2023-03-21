/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:50:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 19:50:23
 * @FilePath: \mysticism-mud\inherit\mxp.c
 * @Description: MXP 功能基类
 * 
 * Copyright (c) 2023 by git config user.email, All Rights Reserved. 
 */

#include <mxp.h>

private nosave mapping mxp_version_info;
private nosave mapping mxp_support_info;

public mixed QueryMXP(){
if(!this_player()) return 0;
return has_mxp(this_player());
}

public void init_mxp() {

 if (!interactive() || !QueryMXP())
        return;
  mxp_version_info = ([]);
  mxp_support_info = ([ MXP_SUPPORT_ENABLED: ({}), MXP_SUPPORT_DISABLED: ({}) ]);
  efun::write(process_mxp(MXPTAG("!-- Set up MXP elements --"), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RNum FLAG=\"RoomNum\" ATT=\"id\" EMPTY"), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RName FLAG=\"RoomName\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RDesc FLAG=\"RoomDesc\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RExits FLAG=\"RoomExit\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT Prompt FLAG=\"Prompt\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT Ex \"<send>\""), QueryMXP()));

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