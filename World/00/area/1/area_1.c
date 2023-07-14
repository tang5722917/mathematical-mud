/*
 * @Author: Donald Duck tang5722917@163.com
 * @Date: 2023-05-20 05:55:52
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-07-14 20:14:34
 * @FilePath: \mysticism-mud\World\00\area\1\area_1.c
 * @Description: 区域1，鲁恩/廷根/ 黑荆棘安保公司-圣塞琳娜教堂
 * Copyright (c) 2023 by Donald Duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <game_world.h>
#include "../../map/1/area_1.h"
inherit CORE_STD_AREA;
/*
                        红月亮街
                           |
                        教堂广场
                           |  (圣塞琳娜教堂)
(通往教堂地下)告解室 —— 教堂大厅 —— 教堂休息室
------------------------------------------------------
                 队长办公室  休息室
                       |   /
(通往地下一层)办公室—— 走廊 —— 会计室
                       |
                      前台（黑荆棘安保公司）
                       |
         杂货铺 ——  佐特兰街 —— 公寓  
                       |
                    贝西克街
                       |
                    猎犬酒吧
--------------------------------------------
地下
                  教堂地下
                     |
            查尼斯门值守室 停尸房
                     |   /      
          武器室 —— 走廊 —— 材料与文献库
                     |
                   炼金室
*/

nosave private mixed *NPC_list = ({
   ({PATH_00_NPC "luoshan",PATH_00_MAP "1/map_0_0_5"}),
   ({PATH_00_NPC "dengeng",PATH_00_MAP "1/map_0_0_3"})
});

nosave protected object *NPC_obs;

void init()
{
   object ob;
   NPC_obs = ({});
   foreach(mixed *npc in NPC_list)
   {
      ob = new(npc[0]);
      ob->move(find_object(npc[1]));
      NPC_obs += ({file_name(copy(ob))});
   }
}

object get_area_npc_obs(int n){
   return NPC_obs[n];}

mixed * get_area_room_obs()
{
   mixed * obs = ({
      ({
         "廷根市","黑夜女神信仰区域"
      }),
      ({
         ({"圣塞琳娜教堂",3,3}),
         ({PATH_00_MAP "1/map_0_1_4",0,1}),
         ({PATH_00_MAP "1/map_0_1_3",1,1}),
         ({PATH_00_MAP "1/map_0_1_2",2,0}),
         ({PATH_00_MAP "1/map_0_1_1",2,1}),
         ({PATH_00_MAP "1/map_0_1_5",2,2})
      }),
      ({
         ({"黑荆棘安保公司",3,6}),
         ({PATH_00_MAP "1/map_0_0_3",0,1}),
         ({PATH_00_MAP "1/map_0_0_1",0,2}),
         ({PATH_00_MAP "1/map_0_0_6",1,0}),
         ({PATH_00_MAP "1/map_0_0_2",1,1}),
         ({PATH_00_MAP "1/map_0_0_4",1,2}),
         ({PATH_00_MAP "1/map_0_0_5",2,1}),
         ({PATH_00_MAP "1/map_0_0_7",3,1}),
         ({PATH_00_MAP "1/map_0_0_8",4,1}),
         ({PATH_00_MAP "1/map_0_0_9",5,1}),
         ({PATH_00_MAP "1/map_0_0_10",3,0}),
         ({PATH_00_MAP "1/map_0_0_11",3,2})
      }),
      ({
         ({"地下",3,4}),
         ({PATH_00_MAP "1/map_1_1_3",0,1}),
         ({PATH_00_MAP "1/map_1_1_2",1,1}),
         ({PATH_00_MAP "1/map_1_1_4",1,2}),
         ({PATH_00_MAP "1/map_1_1_6",2,0}),
         ({PATH_00_MAP "1/map_1_1_1",2,1}),
         ({PATH_00_MAP "1/map_1_1_5",2,2}),
         ({PATH_00_MAP "1/map_1_1_7",3,1})
      })
   });
   return obs;
}
