#include "libmx.h"

void mx_str_reverse(char *s)
{
    int len = mx_strlen(s) - 1;
    int tmp = len;

    for (int i = 0; i <= len / 2; i++, tmp--)
    {
        mx_swap_char(&s[i], &s[tmp]);
    }
}
