
//存储数值型状态
protected mapping living_value;


// 设置属性值
int set_attr(string attr, int value)
{
    if (!mapp(living_value))
        living_value = ([]);
    return living_value[attr] = value;
}

// 获取属性值
int query_attr(string attr)
{
    int data;
    data = living_value[attr];
    return data;
}

// 属性值改变
int query_add_attr(string attr,int value)
{
    int old;
    old = living_value[attr];
    return living_value[attr] = old + value;
}

// 属性值比例变化
int query_sub_attr(string attr,float value)
{
    int old;
    old = living_value[attr];
    return living_value[attr] = (int)(old * value);
}

void set_living_base_value(int base_hp,int base_mp,int base_str,int base_agi,int base_sen,int base_int,int base_cra,int base_luk,int max_mys)
{
    set_attr("base_hp", base_hp); // 基础HP
    set_attr("base_mp", base_mp); // 基础MP
    set_attr("base_str", base_str); // 基础力量
    set_attr("base_agi", base_agi); // 基础敏捷
    set_attr("base_sen", base_sen); // 基础灵性
    set_attr("base_int", base_int); // 基础理智
    set_attr("base_cra", base_cra); // 基础疯狂
    set_attr("base_luk", base_luk); // 基础幸运
    set_attr("max_mys", max_mys);   // 最大非凡

    set_attr("max_hp", base_hp); // 最大HP
    set_attr("max_mp", base_mp); // 最大MP
    set_attr("max_int", base_int); // 最大理智
    set_attr("max_cra", base_cra); // 最大疯狂

    set_attr("hp", base_hp); // 当前HP
    set_attr("mp", base_mp); // 当前MP
    set_attr("str", base_str); // 当前力量
    set_attr("agi", base_agi); // 当前敏捷
    set_attr("sen", base_sen); // 当前灵性
    set_attr("int", base_int); // 当前理智
    set_attr("cra", base_cra); // 当前疯狂
    set_attr("luk", base_luk); // 当前幸运
    set_attr("mys", 0);       // 当前非凡
}


