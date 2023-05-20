/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-20 05:55:52
 * @LastEditors: Donald Duck tang5722917@163.com
 * @LastEditTime: 2023-05-20 10:42:52
 * @FilePath: /mysticism-mud/World/00/map/1/area_1.c
 * @Description: 区域1，鲁恩/廷根/ 黑荆棘安保公司-圣塞琳娜教堂
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
/*
地上1层
                     红月亮街
                       |
                     教堂广场
                       |
(通往教堂地下)告解室 —— 教堂大厅

                 队长办公室  休息室
                       |   /
（通往地下一层）办公室 —— 走廊 —— 会计室
                       |
                      前台（黑荆棘安保公司）
                       |
                    佐特兰街
                       |
                    贝西克街
                       |
                    猎犬酒吧
地下一层
                  武器室  停尸房
                     |  /
                    走廊 —— 查尼斯门值守室 —— 教堂地下
                     |  \
              材料与文献库 炼金室
       
*/
#include <ansi.h>
#include <game_world.h>

inherit CORE_STD_AREA;
