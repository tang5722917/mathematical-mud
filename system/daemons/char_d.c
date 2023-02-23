inherit CORE_CHAR_D;

/ 初始化玩家角色
void init_player(object user)
{
    user->set_user("birthday", time());
    user->set_user("title", "普通人");
    user->set_user("vocation", "common");
    user->set_user("exp", 0); // 对战经验
    user->set_user("wlv", 0);  // 世界等级
    user->status_value->set_living_base_value(
        100,100,10,10,10,0,0,175
    )
}

void setup(object ob)
{

}