#include <ansi.h>
inherit  CORE_STD_NPC;

protected void create()
{
    set_name(MAG "未知神秘存在"NOR,({"?????"})  );
    set("long", HIC "位于上首的椅子上坐着一位未知神秘存在，但由于灰雾的阻挡什么都无法看清" NOR);
} 

void look(object me)
{
    write("你感到有些头晕，并且忘了刚才还在想些什么。\N （你可以试着向那位未知存在问个问题） \n 请试着输入<ask ?????> \n");
}

void answer(object me)
{
    
}