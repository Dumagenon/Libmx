#include "libmx.h"

int mx_get_char_index(const char *str, char c)
{
    if (str == NULL)
        return -2;
    int i;
    for (i = 0; str[i] != c && str[i]; i++);
    
    if (str[i] == '\0')
        return -1;
    return i;
}

// int main() {
//     void *str = NULL;
//     printf("%d", mx_get_char_index(str, 'z'));
//     return 0;
// }
