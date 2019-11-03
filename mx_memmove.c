#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *dist = (unsigned char *)dst;
    unsigned char *source = (unsigned char *)src;
    if (dist < source)
    {
        while (len--)
            *dist++ = *source++;
    }
    else
    {
        unsigned char *lastDst = dist + (len - 1);
        unsigned char *lastSrc = source + (len - 1);
        while (len--)
            *lastDst-- = *lastSrc--;
    }
    return dst;
}

// int main() {
//     unsigned char s[] = "1234567890";
//     mx_memmove(&s[3], &s[5], 3);
//     printf("%s\n", s);

//     unsigned char s1[] = "1234567890";
//     memmove(&s1[4], &s1[3], 3);
//     printf("%s", s1);
//     return 0;
// }
