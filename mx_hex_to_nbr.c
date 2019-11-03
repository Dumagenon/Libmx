#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    if (hex == NULL)
        return 0;

    unsigned long res = 0, m = 1;
    // Colculate the multiplier
    for (int i = 1; hex[i]; i++)
        m *= 16;
    // Count number
    for (int i = 0; hex[i]; i++, m /= 16)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            res = res + (hex[i] - '0') * m;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            res = res + (10 + ((hex[i] - 17) - '0')) * m;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            res = res + (10 + ((hex[i] - 49) - '0')) * m;
        else
            return 0;
    }
    return res;
}
