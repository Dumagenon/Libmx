#include "libmx.h"

char *mx_strdup(const char *str)
{
    if (str == NULL)
        return NULL;

    int len = mx_strlen(str);
    char *arr = mx_strnew(len - 1);

    if (arr)
        mx_strcpy(arr, str);
    else
        return NULL;

    return arr;
}
