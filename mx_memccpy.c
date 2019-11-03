#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    unsigned char *cdst = (unsigned char *)dst,
                  *csrc = (unsigned char *)src;

    for (size_t i = 0; *csrc != (unsigned char)c && i < n; i++) // копируем побайтно
        *cdst++ = *csrc++;

    if (*csrc == c)
    {
        *cdst = c;
        return cdst + 1;
    }
    return NULL;
}

// int main() {
//     unsigned char  src[15] = "Hello world";  // источник
//     unsigned char dst[15] = "Abaldet' pro";  // буфер назначения
//     printf("%s\n", mx_memccpy(dst, src, 'o', 11));
//     printf("%s\n", dst);
//     return 0;
// }
