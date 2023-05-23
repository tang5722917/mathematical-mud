/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-20 05:55:52
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-23 19:55:37
 * @FilePath: \mysticism-mud\World\00\map\1\area_1.c
 * @Description: 区域1，鲁恩/廷根/ 黑荆棘安保公司-圣塞琳娜教堂
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
inherit CORE_STD_AREA;
protected string area_map = 
HBGRN"地上"NOR"
                        "BCYN"红月亮街"NOR"
                           |
                        教堂广场
                           |  (圣塞琳娜教堂)
(通往教堂地下)告解室 —— 教堂大厅 —— 教堂休息室
"YEL"------------------------------------------------------"NOR"
                 队长办公室  休息室
                       |   /
(通往地下一层)办公室—— 走廊 —— 会计室
                       |
                      前台（黑荆棘安保公司）
                       |
                    "BCYN"佐特兰街"NOR"
                       |
                    "BCYN"贝西克街"NOR"
                       |
                    猎犬酒吧
"HBYEL"--------------------------------------------"NOR"
"HBGRN"地下一层"NOR"
                  教堂地下
                     |
            查尼斯门值守室 停尸房
                     |   /      
          武器室 —— 走廊 —— 材料与文献库
                     |
                   炼金室
";
string get_area_map(){return area_map;}
