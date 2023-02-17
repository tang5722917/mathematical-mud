inherit "CORE_LOGIN_D";

protected void welcome(object ob)
{
    color_cat(MOTD);
    write("\n^_^!请输入你的登录ID:\n");
    write("\n^_^!请输入你的登录ID:");
    input_to("get_id", ob);
}