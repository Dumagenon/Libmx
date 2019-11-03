#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    if (little_len > big_len || !little_len || !big_len)
        return NULL;
    if (little_len > 1)
    {
        unsigned char *haystack = (unsigned char *)big;
        unsigned char *needle = (unsigned char *)little;

        for (size_t i = 0; i <= big_len - little_len + 1; i++)
        {
            if (!mx_memcmp(haystack, needle, little_len))
            {
                return (void *)haystack;
            }
            haystack++;
        }
    }
    else
    {
        return mx_memchr(big, ((unsigned char *)little)[0], big_len);
    }
    return NULL;
}

// int main (void)
// {
//   char src[] = "Trinity is my wife",
//     src2[] = "ity";
//   char *sym;

//   // Вывод исходного массива
//   printf ("src old: %s\n",src);

//   // Поиск требуемого символа
//   sym = mx_memmem(src, 10, src2, 1);

//   // Вывод исходного массива
//   printf ("src new: %s\n", sym);

//   return 0;
// }
