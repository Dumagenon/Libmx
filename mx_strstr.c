#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    while (*haystack)
    {
        if (*haystack == *needle)
        {
            int i;
            char *tmp = (char *)haystack;
            haystack++;
            for (i = 1; needle[i] && *haystack == needle[i]; i++)
                haystack++;
            if (needle[i] == '\0')
                return tmp;
            else
                haystack--;
        }
        haystack++;
    }
    return NULL;
}

// int main() {
//     char str[] = "This pLLinurogram wrote on Linux";
//     printf("%s", mx_strstr(str, "Linux"));
//     return 0;
//  }
