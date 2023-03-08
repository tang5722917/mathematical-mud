#include <ansi.h>
inherit PATH_DIR "inherit/living";

void create()
{
    set_name(YEL "神秘的光团"NOR,({"???"})  );
    set("long", HIC "这是一个神秘的光团，让人无法挪开视线\n可以尝试使用search或sh调查一下" NOR);
    set_visible(0);
    set_fight_living(0);
}

void search(object me,object env)
{
    object ob;
    write("这个光团有着神秘的魅力，你的身体不知不觉的靠近了它\n 
这时你的脑海中响起一个声音，“与它战斗吧！\n (使用fight或f命令攻击指定目标，请输入f ???)");
    ob = this_object();
    me->modify_user_status(file_name(ob),3,0);
}