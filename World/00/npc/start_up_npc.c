#include <ansi.h>
#include <mxp.h>
inherit  CORE_STD_NPC;

protected void create()
{
    set_name(MAG "未知神秘存在"NOR,({"?????"})  );
    set("long", HIC "位于上首的椅子上坐着一位未知神秘存在，但由于灰雾的阻挡什么都无法看清" NOR);
}

void look(object me,object env)
{
    object mxp_test = new("/World/base/card/01/paper_replace");
    write("你感到有些头晕，并且忘了刚才还在想些什么。\n （你可以试着向那位未知存在问个问题） \n 请试着输入（ask ?????） \n");
}

void answer(object me,object env)
{
    object ob;
    write("神秘的存在： ............... \n 这时你突然发现面前多了个光团\n(使用look(l)试着看一下吧)");
    ob = env->ob_in_room("???");
    me->modify_user_status(file_name(ob),1,0);
}

string honor_name(object me,object ob)
{
    return "神秘的那位存在";
}
