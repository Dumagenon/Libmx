#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (!ptr && size)
        return malloc(size);
    if (size == 0 && ptr)
    {
        free(ptr);
        return NULL;
    }
    size_t len = mx_strlen(ptr);
    void *res;
    if (len > size)
    {
        res = malloc(len);
        if (!res)
            return NULL;
        res = mx_memmove(res, ptr, len);
    }
    else
    {
        res = malloc(size);
        if (!res)
            return NULL;
        res = mx_memmove(res, ptr, size);
    }
    return res;
}

// int main(void)
// {
//   char *p = mx_strdup("Hello my dear friend");
//   if(!p) {
//     printf("Allocation error.");
//     exit (1);
//   }
//   p = (char *) realloc (p, 15);
//   if(!p) {
//     printf("Allocation error.");
//     exit (1);
//   }
//   printf("%s - %p - %lu", p, (void *)&p, malloc_size(p));
// //printf("-- /%s", p);
//   free(p);
//   return 0;
// }
