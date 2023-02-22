inherit INHERIT_PATH "status_value"
inherit INHERIT_PATH "status_mystic"

// type 0  非人非怪物NPC
// type 1  人
// type 2  非怪物

//attack 0 不可攻击生物
//attach 1  可攻击生物
void set_living_base_value(int base_hp,int base_mp,
    int base_str,int base_agi,int base_int,int base_cra,
    int base_luk,int max_mys,int mys_num, int type,int attack)
{
    set_attr("base_hp", base_hp); 
    set_attr("base_mp", base_mp); 
    set_attr("base_str", base_str); 
    set_attr("base_agi", base_agi); 
    set_attr("base_int", base_int); 
    set_attr("base_cra", base_cra); 
    set_attr("base_luk", base_luk); 
    set_attr("max_mys", max_mys); 
    set_attr("mys_num", mys_num); 
    set_attr("type", type); 
    set_attr("attack", attack); 
}