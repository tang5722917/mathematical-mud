/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-24 10:10:44
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-29 20:04:21
 * @FilePath: \mysticism-mud\inherit\space\map_d\show_map_d.c
 * @Description: 输出地图数据
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */
#include <ansi.h>
#include <mxp.h> 
#include <game_world.h> 

 string map_line(mixed * map_line, int x,int width,object env,object user)
 {
     string str="",room_name="";
     string width_s = "%-"+width+"s";
     mapping exits;
     object ob;
     for(int i=0;i<x;i++)
     {
        room_name="";
        if(map_line[i] != 0){
            ob = map_line[i];
            if(ob == env){
                room_name += repeat_string(" ",(width - sizeof(ob->mxp_name()))/2-1);
                room_name += BRED + ob->get_room_name() + NOR;
            }
            else{
                room_name +=  repeat_string(" ",(width - sizeof(ob->mxp_name()))/2-1);
                room_name += ob->mxp_sprintf(ob->print_mxp_name_all(MXP_MAP),width,user);
             }
             str += sprintf(width_s,room_name);
             if(i < x-1)
                 if(map_line[i+1] != 0){
                     exits = map_line[i]->query("exits");
                     if(exits["east"] != 0)
                         str+="—— ";
                 }
         }
         else str += sprintf(width_s+"    ","");
     }
     str += "\n";
     return str;
 }
 
 string map_line_connect(mixed *map_line,mixed * map_line_n,int x,int width)
 {
     mapping exits;
     string s="",st;
     string width_s = "%|"+width+"s";
     string str="";
     for(int i=0;i<x;i++){
         if(map_line[i] == 0){
             str += sprintf(width_s+"   "," ");
             continue;
         }
         exits = map_line[i]->query("exits");
         st = width_s;
         if(exits["southwest"] != 0)
             st ="/" +st;
         if(exits["south"] != 0)
             s+="|";
         if(exits["southeast"] != 0)
             st =st +"\\";
         str += sprintf(st+"   ",s);
         s="";
     }
     //if(exits["southwest"] != 0);
     return str+"\n";
 }
 
 string map_matrix(mixed * map_data, int x, int y, int width,object env,object user)
 {
     string str="";
     mixed *map_line;
     for(int i=0;i<y;i++)
     {
         map_line = map_data[i];
         str += map_line(map_line, x,width,env,user);
         if(i < y-1)
             str += map_line_connect(map_line,map_data[i+1],x,width);
     }
     return str;
 }
 
 mixed * get_data_matrix(int x,int y)
 {
     mixed *m = allocate(y);
     for(int i=0;i<y;i++)
         m[i] = allocate(x,0);
     return m;
 }
 
string show_map(object me)
{
     object env = environment(me);
     object o;
     mixed obs = env->get_map_info();
     mixed *map_show_info;
     string show_map;
     mixed *room_line ;
     int x,y,x1,y1;
     show_map =HBWHT+BLK+obs[0][0]+NOR+"-"+HBCYN+obs[0][1]+NOR + "\n";
     show_map +=BRED +"   "+NOR+"-"+ "当前玩家所在地" + "\n";
     for(int j=1;j<sizeof(obs);j++)
     {
         map_show_info =  obs[j][0];
         show_map += GRN+ map_show_info[0]+NOR+"\n";
         x1 = map_show_info[1];
         y1 = map_show_info[2];
         room_line = get_data_matrix(x1,y1);
         for(int i=1;i<sizeof(obs[j]);i++)
         {
             map_show_info = obs[j][i];
             o = load_object(map_show_info[0]);
             y = map_show_info[1];
             x = map_show_info[2];
             room_line[y][x] = o;
         }
         show_map += map_matrix(room_line, x1, y1, 8, env,me);
         if(j < sizeof(obs)-1)
             show_map +=YEL"--------------------------------------------"NOR"\n";
     }
     show_map +=BYEL"--------------------------------------------"NOR;
     return show_map;
}
