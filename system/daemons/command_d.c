inherit CORE_COMMAND_D;

private nosave mapping MYS_aliases = ([
    "sc":"score",
    "b":"bag"
]);

void create()
{
    add_alias(MYS_aliases);
}