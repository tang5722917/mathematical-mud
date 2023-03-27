/***
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:46:57
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-03-21 19:47:02
 * @FilePath: \mysticism-mud\include\mxp.h
 * @Description: MXP 支持头文件
 * @
 * @Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#ifndef MXP_H
#define MXP_H

#define MXP_SUPPORT_ENABLED  "mxp_enabled_features"
#define MXP_SUPPORT_DISABLED "mxp_disabled_features"

/* strings */

#define MXP_BEG "\x03"
#define MXP_END "\x04"
#define MXP_AMP "\x05"

/* characters */

#define MXP_BEGc '\x03'
#define MXP_ENDc '\x04'
#define MXP_AMPc '\x05'

/* constructs an MXP tag with < and > around it */

#define MXPTAG(arg) sprintf("%s%s%s", MXP_BEG, arg, MXP_END)

#define ESC1 "\x1B"  /* esc character */

#define MXPMODE(arg) sprintf("%s[%dz", ESC1, arg)
#define MXP_write(arg) efun::write(process_mxp(MXPTAG(arg), QueryMXP()))

#define USER_MXP this_player()->mxp_status()

#endif // MXP_H
