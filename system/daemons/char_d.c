inherit CORE_CHAR_D;
#include <user.h>

// 初始化玩家角色
void init_player(object user, mixed *data...)
{
    user->set("birthday", time());
    user->set("title", "普通人");
    user->set("vocation", "无业");
    user->set("exp_win", 0); // 对战经验_胜
    user->set("exp_fai", 0); // 对战经验_败
    user->set("exp_equ", 0); // 对战经验_平
    user->set("wlv", 0);     // 世界等级
    user->set_living_base_value(100,100,10,10,10,100,0,0,175);
    user->add_mystic(find_object(INIT_MYS));
    shout("欢迎新玩家！");
}
//初始化玩家登录
void setup(object ob)
{

}
