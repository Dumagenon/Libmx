#include "libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
    unsigned char *tmp = (unsigned char *)b;
    for (size_t i = 0; i < len; i++)
    {
        *tmp++ = c;
    }
    return (void *)b;
}

// int main() {
//     char str[5];
//     mx_memset(str, '\0', 5);
//     for(int i = 0; i < 5; i++)
//         printf("%c", str[i]);
//     return 0;
// }
