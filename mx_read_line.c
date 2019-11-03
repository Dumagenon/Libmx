#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{
    static char *remainder = NULL;
    char buf[buf_size + 1];
    int reading = 0, delim_index = -1;
    char *tmp_str = NULL, *tmp = NULL;
    if (remainder)
    {
        tmp_str = mx_strdup(remainder);
    }

    while ((reading = read(fd, buf, buf_size)) >= 0)
    {
        buf[reading] = '\0';
        tmp = mx_strjoin(tmp_str, buf);
        mx_strdel(&tmp_str);
        tmp_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(tmp_str, delim);
        if (delim_index != -1)
        {
            tmp_str[delim_index] = '\0';
            if (remainder)
            {
                mx_strdel(&remainder);
            }
            remainder = mx_strdup(tmp_str + delim_index + 1);
            break;
        }
        if (reading == 0)
        {
            if (remainder)
            {
                mx_strdel(&remainder);
            }
            break;
        }
    }
    if (reading == -1)
    {
        return -1;
    }
    if (delim_index == -1)
    {
        free(*lineptr);
        mx_strdel(&tmp_str);
        *lineptr = mx_strnew(0);
        return 0;
    }
    *lineptr = mx_strdup(tmp_str);
    mx_strdel(&tmp_str);
    return mx_strlen(*lineptr);
}

// int main()
// {
//     int fd = open("file.txt", O_RDONLY);
//     char *str = NULL;
//     int res = mx_read_line(&str, 20, '.', fd);
//     printf("- %s - --> %d", str, res);
//     mx_strdel(&str);
//     close(fd);
//     system("leaks -q libmx");
//     return 0;
// }
