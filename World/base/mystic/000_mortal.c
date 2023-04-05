/*
 * @Author: Tangzp tang5722917@163.com
 * @Date: 2023-04-06 05:47:44
 * @LastEditors: Tangzp tang5722917@163.com
 * @LastEditTime: 2023-04-06 06:01:46
 * @FilePath: \mysticism-mud\World\base\mystic\000_mortal.c
 * @Description: 非凡特性  -- 凡人
 * Copyright (c) 2023 by Tangzp email: tang5722917@163.com, All Rights Reserved.
 */

 inherit CORE_STD_MYSTIC;
 //非凡特性编号000
 int rank_num()
 {
     return 0;
 }
 //序列等级10
 int mystic_rank()
 {
     return 10;
 }
 
 //非凡特性名称
 string mystic_name(){return "普通人";}
 //非凡特性short 介绍
 string mystic_short(){return "你只是一个平凡的普通人，在这个不平静的世界一定要注意安全！";}
