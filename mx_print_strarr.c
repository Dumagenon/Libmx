#include "libmx.h"

// Function works with NULL terminated array
void mx_print_strarr(char **arr, const char *delim)
{
    if (arr != NULL || delim != NULL)
    {
        for (int i = 0; arr[i] != NULL; i++)
        {
            mx_printstr(arr[i]);
            if (arr[i + 1] != NULL)
                mx_printstr(delim);
        }
        write(1, "\n", 1);
    }
}

// int main() {
//     char *arr[6] = {"Hello", "darkness", "my", "old", "friend", NULL};
//     mx_print_strarr(arr, "--->");
//     return 0;
// }
