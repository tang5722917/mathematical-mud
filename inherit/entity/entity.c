/*
 * @Author: Donald duck tang5722917@163.com
 * @Date: 2023-05-09 20:05:57
 * @LastEditors: Donald duck tang5722917@163.com
 * @LastEditTime: 2024-01-04 18:21:31
 * @FilePath: \mysticism-mud\inherit\entity\entity.c
 * @Description: entity基类
 * Copyright (c) 2024 by Donald duck email: tang5722917@163.com, All Rights Reserved.
 */


inherit CORE_STD_TEST;
inherit _MXP;
inherit _NAME;
inherit _MOVE;
inherit _MESSAGE;

string print_card_name(object user);
string print_equip_name(object user);
string print_summon_name(object user);
string print_status_name(object user);
string print_materials_name(object user);
string print_mxp_other(object user);
/*开头数字代表类型
*1  Card
*2  Equit
*3  Summon
*4  Skill
*5  Status
*6  Materials
*7  继承自property特殊物品
*8  Common  //公共物品
*9  保留
*/
int entity_id(){return 0;}
int id_num(){return entity_id();}
string entity_description(){return "";}
string id_look(){return "Entity";}
varargs string print_name(object user,object ob)
{
    string str = "";
    if(!ob)
        ob = this_object();
    if(!user)
        user = this_player();
    if( inherits(CORE_STD_CARD,ob)  )
        str += ob->print_card_name(user);
    else if( inherits(CORE_STD_EQUIP,ob)  )
        str += print_equip_name(user);
    else if( inherits(CORE_STD_SUMMON,ob)  )
        str += ob->print_summon_name(user);
    else if( inherits(CORE_STD_STATUS,ob)  )
        str += ob->print_status_name(user);
    else if( inherits(CORE_STD_MATERIALS,ob)  )
        str += ob->print_materials_name(user);
    else
        str += ob->print_mxp_other(user);
    return str;
}
