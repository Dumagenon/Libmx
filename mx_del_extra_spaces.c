#include "libmx.h"

char *mx_del_extra_spaces(const char *str)
{
  char *tmp = mx_strtrim(str);
  int len = mx_strlen(tmp), i, j;
  char *work = mx_strnew(len - 1);

  for (i = 0, j = 0; tmp[i]; i++)
  {
    if (!(mx_isspace(tmp[i])))
    {
      work[j] = tmp[i];
      j++;
    }
    else if (mx_isspace(tmp[i]) && !(mx_isspace(tmp[i + 1])))
    {
      work[j] = ' ';
      j++;
    }
  }
  char *res = mx_strndup(work, mx_strlen(work));
  mx_strdel(&work);
  mx_strdel(&tmp);
  return res;
}

// int main() {
//   char name[] = "\f My   name...  \nis \r Neo   \t\n ";
//   char *res = mx_del_extra_spaces(name);
//   printf("%s\n", res);
//   mx_strdel(&res);
//   system("leaks -q libmx");
//   return 0;
// }
