
inherit CORE_STD_FIGHT_S;

string * fight_init_user()
{   
    string * str=({});
    str +=({"突然感觉体内涌现一股神秘的力量！"});
    str +=({"同时脑海中有一个清晰的声音响起——“你要准备开始战斗”"});
    return str;
}
string * fight_init_env()
{
    string * str=({});
    str +=({"模糊的人影抬起头注视着你"});
    return str;
}