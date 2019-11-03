#include "libmx.h"

void mx_del_strarr(char ***arr)
{
    if (arr != NULL)
    {
        char **p = *arr;
        while (*p)
        {
            mx_strdel(p);
            p++;
        }
        free(*arr);
        *arr = NULL;
    }
}

// int main(void) {
//     char *s0 = (char *) malloc(5);
//     char *s1 = (char *) malloc(6);
//     char *s2 = (char *) malloc(3);
//     char **ss = (char **) malloc(4 *sizeof(char *));
//     ss[0] = s0;
//     ss[1] = s1;
//     ss[2] = s2;
//     ss[3] = NULL;
//     mx_del_strarr(&ss);
//     if(ss == NULL) printf("Done");
//     else printf("False");
//     system("leaks -q libmx");
//     return 0;
// }
