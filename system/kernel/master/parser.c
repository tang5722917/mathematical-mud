#include <parser_error.h>

string parser_error_message(int type, object ob, mixed arg, int flag)
{
    switch (type)
    {
    case ERR_IS_NOT:
    case ERR_NOT_LIVING:
    case ERR_NOT_ACCESSIBLE:
    case ERR_AMBIG:
    case ERR_ORDINAL:
    case ERR_ALLOCATED:
    case ERR_THERE_IS_NO:
    case ERR_BAD_MULTIPLE:
    case ERR_MANY_PATHS:
    default:
#ifndef DEBUG_MYSTICISM
        return sprintf("%s",arg);
#endif
#ifdef DEBUG_MYSTICISM
        return sprintf("parser_error_message : type = %d, ob = %O, arg = %O, flag = %d", type, ob, arg, flag);
#endif
    }
}