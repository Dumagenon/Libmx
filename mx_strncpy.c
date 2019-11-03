#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    if (dst == NULL || src == NULL)
        return NULL;

    int i;
    for (i = 0; i < len; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}
