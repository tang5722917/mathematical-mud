/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-06 11:14:11
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2023-05-16 15:37:57
 * @FilePath: \mysticism-mud\inherit\std\queue.c
 * @Description: 队列数据结构基类
 * Copyright (c) 2023 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */

 nosave protected mixed *queue;
 nosave protected string name;

 void create(string q_name){name = q_name;}
 int length(){return sizeof(queue);}
 int push(mixed item)
 {
    if(!queue)
        queue = ({});
    queue +=({item});
    return sizeof(queue);
 }

//type 0 需要copy，1不需要copy
//buffer/class/object/array 需要copy
varargs mixed pop(int type)
 {
    mixed q;
    if(!queue || !sizeof(queue))
        return 0;
    if(!type)
        q = copy(queue[0]);
    else
        q = queue[0];
    queue -=({queue[0]});
    return q;
 }
 void sort(string fun,object ob)
 {
    if(queue && sizeof(queue))
        queue = sort_array(queue, fun , ob);
} 
 void clear(){queue = ({});}
 void remove(){destruct(this_object());}
