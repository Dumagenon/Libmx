#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (ptr == NULL && size > 0)
        return malloc(size);
    if (size == 0)
    {
        free(ptr);
        char *res = malloc(malloc_size(NULL));
        mx_memcpy(res, "", 16);
        return res;
    }
    void *nptr = malloc(size);
    if (nptr == NULL)
        return NULL;

    mx_memcpy(nptr, ptr, malloc_size(ptr));
    free(ptr);
    return nptr;
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
