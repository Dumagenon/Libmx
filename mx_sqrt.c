int mx_sqrt(int x)
{
    unsigned int y = x;

    if (x == 0 || x == 1)
        return x;
    for (unsigned int i = 1; i * i <= y; i++)
        if (y == i * i)
            return i;
    return 0;
}
