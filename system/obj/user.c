#include <user.h>
inherit CORE_USER_OB;

protected mapping user_data;

void create()
{
    seteuid(0); // export_uid
}


// 从游戏中移除这个角色
void remove()
{
    ::remove();
    // todo 玩家存档处理
    save();
    destruct(this_object());
}


// 设置属性值
int set_user(string attr, int value)
{
    return user_data[attr] = value;
}

// 获取属性值
int query_user(string attr)
{
    int data;
    data = user_data[attr];
    return data;
}


void window_size(int width, int height)
{
    set_temp("window_size/width", width);
    set_temp("window_size/height", height);
    //message("system", "终端窗口大小设置为 " + width + " × " + height + "。\n", this_object());
}


void user_input_monitor()
{
    //输入的指令统计数清0
    input_num = 0;
}

// 玩家心跳事件
void heart_beat()
{
    mapping condition;
    if (mapp(condition = query("condition")))
    {
        foreach (string key, mapping value in condition)
        {
            if (value["time"] <= 0)
            {
                catch(replace_string(key, "#", "/")->stop_effect(this_object()));
                delete("condition/" + key);
                continue;
            }

            if (value["heart_beat"] > 0 && !(value["time"] % value["heart_beat"]))
                catch(replace_string(key, "#", "/")->heart_beat_effect(this_object()));

            add("condition/" + key + "/time", -1);
        }
    }
    //玩家监控函数
    user_input_monitor();
    //玩家1s显示逐行信息
    user_output_one();
}
