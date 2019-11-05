#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *s1_c = s1, *s2_c = s2;

    while (n--)
    {
        if (*s1_c != *s2_c)
            return *s1_c - *s2_c;
        s1_c++;
        s2_c++;
    }
    return 0;
}

// int main() {
//     unsigned char  src[18] = "Hello my friend!";  // источник
//     unsigned char dst[18] = "Hello my friend! ";  // буфер назначения
//     printf("%d\n", mx_memcmp(dst, src,  20));
//     printf("%d\n", memcmp(dst, src,  20));
//     return 0;
// }
