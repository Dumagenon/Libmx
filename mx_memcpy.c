#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    int i, m;
    unsigned long *wdst = (unsigned long *)dst; // текущая позиция в буфере назначения
    unsigned long *wsrc = (unsigned long *)src; // текущая позиция в источнике
    unsigned char *cdst, *csrc;

    for (i = 0, m = n / sizeof(long); i < m; i++) // копируем основную часть блоками по 8 байт
        *(wdst++) = *(wsrc++);                    // (в зависимости от платформы)

    cdst = (unsigned char *)wdst;
    csrc = (unsigned char *)wsrc;

    for (i = 0, m = n % sizeof(long); i < m; i++) // остаток копируем побайтно
        *(cdst++) = *(csrc++);

    return dst;
}

// int main() {
//     unsigned char  array[] = "Hello world";               // источник
//     unsigned char byte_array[sizeof(array)];  // буфер назначения
//     printf("%s\n", mx_memcpy(byte_array, array, 12));
//     return 0;
// }
