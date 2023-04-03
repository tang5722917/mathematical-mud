/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-03-21 19:48:21
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-04-03 14:57:54
 * @FilePath: \mysticism-mud\system\kernel\simul_efun\process_mxp.c
 * @Description: MXP的 sefun
 *
 * Copyright (c) 2023 by git config user.email, All Rights Reserved.
 */
#include <mxp.h>

/*
**   Function: process_mxp
**
**    Purpose: Process MXP.
**
** Parameters: string msg, the msg to transform
**
**    Returns: string
*/

public mixed QueryMXP(){
    if(!this_player()) return 0;
    return has_mxp(this_player());
    }

public string process_mxp(string msg, int does_mxp) {
    int line = 0;
    int length = 0;
    int i = 0;
    int inTag = 0;
    int inEntity = 0;

    string *original_lines = explode(msg, "\n");
    string *processed_lines = allocate(sizeof(original_lines));
    if(!does_mxp) return msg;

    for (line = 0; line < sizeof(original_lines); line++) {
    processed_lines[line] = does_mxp ? MXPMODE(4) : "";

        length = sizeof(original_lines[line]);

        for (i = 0; i < length; i++) {
            if (inTag) { /* in a tag, eg. <send> */
                if (original_lines[line][i..i] == MXP_END) {
                    inTag = 0;

                    if (does_mxp) {
                        processed_lines[line] += ">";
                    }
                } else if (does_mxp) { /* copy tag only when MXP does_mxp */
                    processed_lines[line] += original_lines[line][i..i];
                }
            } else if (inEntity) { /* in a tag, eg. <send> */
                if (does_mxp) { /* copy tag only when MXP does_mxp */
                    processed_lines[line] += original_lines[line][i..i];
                }

                if (original_lines[line][i..i] == ";") {
                    inEntity = 0;
                }
            } else {
                if (original_lines[line][i..i] == MXP_BEG) {
                    inTag = 1;

                    if (does_mxp) {
                        processed_lines[line] += "<";
                    }
                } else if (original_lines[line][i..i] == MXP_END) { /* should not get this case */
                    processed_lines[line] += ">";
                } else if (original_lines[line][i..i] == MXP_AMP) {
                    inEntity = 1;

                    if (does_mxp) {
                        processed_lines[line] += "<";
                    }
                } else if (does_mxp) {
                    if (original_lines[line][i..i] == "<") {
                        processed_lines[line] += "&lt;";
                    } else if (original_lines[line][i..i] == ">") {
                        processed_lines[line] += "&gt;";
                    } else if (original_lines[line][i..i] == "&") {
                        processed_lines[line] += "&amp;";
                    } else if (original_lines[line][i..i] == "\"") {
                        processed_lines[line] += "&quot;";
                    } else {
                        processed_lines[line] += original_lines[line][i..i];
                    }
                } else { /* not MXP - just copy character */
                    processed_lines[line] += original_lines[line][i..i];
                }
            }
        }
    }
    return implode(processed_lines, "\n");
}

void MXP_write(string arg)
{
    if(USER_MXP)
        efun::write(process_mxp(MXPTAG(arg), QueryMXP()));
    else
        efun::write(arg);
}

void MXP_message(string typ,string msg,object ob)
{
    if(MXP_USER(ob))
        message(typ,process_mxp(MXPTAG(msg),QueryMXP()),ob);
    else
        message(typ,msg,ob);
}
