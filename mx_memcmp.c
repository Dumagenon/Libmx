#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    while (--n && (*((unsigned char *)s1) == *((unsigned char *)s2)))
    {
        s1 = (unsigned char *)s1 + 1;
        s2 = (unsigned char *)s2 + 1;
    }
    return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

// int main() {
//     unsigned char  src[15] = "y ";  // источник
//     unsigned char dst[15] = "y";  // буфер назначения
//     printf("%d\n", mx_memcmp(dst, src,  20));
//     printf("%d\n", memcmp(dst, src,  20));
//     return 0;
// }
