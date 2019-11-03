#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
        return -1;

    int count = 0, subLen = mx_strlen(sub), len = mx_strlen(str) / subLen;
    for (int i = 0; i < len; i++)
    {
        if (mx_strstr(str, sub))
        {
            str = mx_strstr(str, sub);
            count++;
            str += subLen;
        }
    }
    return count;
}

// int main() {
//    char s[] = "***1*_2__341118956_1*_7_11189***";
//    printf("Совпадений: %d\n", mx_count_substr(s, "11"));
//    printf("Совпадений: %d\n", mx_count_substr(s, "1*"));
//    printf("Совпадений: %d\n", mx_count_substr(s, "189"));
//    printf("Совпадений: %d\n", mx_count_substr(s, NULL));
//    printf("Совпадений: %d\n", mx_count_substr(NULL, "1"));
//    return 0;
// }
