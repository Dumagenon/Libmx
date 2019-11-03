#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    
    int index = 0, bag = 0, len = mx_strlen(str);
    char *tmp = (char*)sub;
    while (*str) {
        sub = tmp;
        if (*str == *sub)
        {
            while (*sub && *str == *sub)
            {
                str++;
                sub++;
                bag++;
            }
            if (*sub == '\0')
            {
                if(index > len) return -1;
                return index;
            }
            else
            {
                index += bag;
                bag = 0;
            }
        }
        index++;
        str++;
    }
    return -1;
}

// int main() {
//     printf("Case[1] position[12] -> %d\n", mx_get_substr_index("McDoonDaonalDonds", "Don"));
//    printf("Case[2] position[-1] -> %d\n", mx_get_substr_index("McDonalds", "Donatello"));
//    printf("Case[3] position[3] -> %d\n", mx_get_substr_index("McDonalds Donuts", "on"));
//    printf("Case[4] position[-2] -> %d\n", mx_get_substr_index(NULL, "Don"));
//    printf("Case[5] position[-1] -> %d\n", mx_get_substr_index("McDonaldsHello", "Hello"));
//    printf("Case[6] position[?] -> %d\n", mx_get_substr_index("McDonalds", "\0"));
// //     printf("%d", mx_get_substr_index("MaDonaMcadlds", "Dsc"));
//      return 0;
// }
