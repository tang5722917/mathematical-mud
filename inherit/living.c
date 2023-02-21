#include <dbase.h>

inherit CORE_LIVING ;

// 角色激活
void setup()
{
    seteuid(getuid(this_object()));
    set_heart_beat(1);
    enable_living(); // COMMAND 中定义的生物激活方法
    CHAR_D->setup(this_object());
}

// 从游戏中移除这个生物
void remove()
{
    destruct(this_object());
}


// 设置属性值
int set_attr(string attr, int value)
{
    return set("attr/" + attr, value);
}
// 更新属性值
int add_attr(string attr, int value)
{
    return add("attr/" + attr, value);
}
// 获取属性值
int query_attr(string attr)
{
    return query("attr/" + attr);
}

void set_living_base_value(int base_hp,int base_mp,
    int base_str,int base_agi,int base_int,int base_cra,int base_luk,int max_mys,int mys_num )
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
}

// 当前力量
int query_str()
{
    return query_attr("str");
}

// 基础力量
int query_base_str()
{
    return query_attr("base_str");
}
// 当前敏捷
int query_agi()
{
    return query_attr("agi");
}

// 基础敏捷
int query_base_agi()
{
    return query_attr("base_agi");
}

// 当前理智
int query_int()
{
    return query_attr("int");
}

// 基础理智
int query_base_int()
{
    return query_attr("base_int");
}
// 当前疯狂
int query_cra()
{
    return query_attr("cra");
}
// 基础疯狂
int query_base_cra()
{
    return query_attr("base_cra");
}
// 当前幸运
int query_luk()
{
    return query_attr("luk");
}
// 基础幸运
int query_base_luk()
{
    return query_attr("base_luk");
}

// 基础HP
int query_base_hp()
{
    return query_attr("base_hp") ;
}
// 基础MP
int query_base_mp()
{
    return query_attr("base_mp") ;
}
// 当前HP
int query_hp()
{
    return query_attr("hp");
}
// 当前MP
int query_mp()
{
    return query_attr("mp");
}


// 最大非凡
int query_max_mys()
{
    return query_attr("max_mys");
}
// 当前非凡
int query_mys()
{
    return query_attr("mys");
}




// 恢复
int set_str_full() { 
    return set_attr("str", mystic_affect_str()); 
}
int set_agi_full() { 
    return set_attr("agi", mystic_affect_agi()); 
}
int set_hp_full() { 
    return set_attr("hp", mystic_affect_hp()); 
}
int set_mp_full() {
     return set_attr("mp", mystic_affect_mp()); 
}
int set_int_full() {
     return set_attr("int", mystic_affect_int()); 
}
int set_cra_clear() {
     return set_attr("cra", mystic_affect_cra()); 
}
int set_luk_full() {
    return set_attr("luk", mystic_affect_luk()); 
}

void set_all_full()
{
    set_str_full()
    set_agi_full()
    set_hp_full();
    set_mp_full();
    set_int_full();
    set_cra_clear()
    set_luk_full()
}
// 清零(die)
int set_hp_zero() { return set_attr("hp", 0); }
int set_mp_zero() { return set_attr("mp", 0); }
void set_hpmp_zero()
{
    set_hp_zero();
    set_mp_zero();
}
// 判断
int is_hp_full() { return query_hp() >= query_max_hp(); }
int is_mp_full() { return query_mp() >= query_max_mp(); }
int is_hpmp_full()
{
    return is_hp_full() && is_mp_full();
}

int mystic_affect_hp(object mys){return mys->affect_hp(this_object());}
int mystic_affect_mp(object mys){return mys->affect_mp(this_object());}
int mystic_affect_str(object mys){return mys->affect_str(this_object());}
int mystic_affect_agi(object mys){return mys->affect_agi(this_object());}
int mystic_affect_int(object mys){return mys->affect_int(this_object());}
int mystic_affect_cra(object mys){return mys->affect_cra(this_object());}
int mystic_affect_luk(object mys){return mys->affect_luk(this_object());}
