#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    char *mem = NULL;
    if (n > (unsigned long)mx_strlen(s1))
    {
        mem = mx_strnew(mx_strlen(s1));
        n = mx_strlen(s1);
    }
    else
        mem = mx_strnew(n);

    return mx_strncpy(mem, s1, n);
}

// int main() {
//     void * str = NULL;
//     printf("%s", mx_strndup(str, 5));
//     return 0;
// }
