#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    while (*haystack)
    {
        if (*haystack == *needle)
        {
            int i;
            char *tmp = (char *)haystack;
            for (i = 0; needle[i] && *haystack == needle[i]; i++)
                haystack++;
            if (needle[i] == '\0')
                return tmp;
        }
        haystack++;
    }
    return NULL;
}

// int main() {
//     char str[] = "This program wrote on Linux Ubuntu";
//     printf("%s", mx_strstr(str, "Linux"));
//     return 0;
// }
