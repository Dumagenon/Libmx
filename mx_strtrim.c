#include "libmx.h"

bool mx_isspace(char c)
{
  if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
    return 1;
  else
    return 0;
}

char *mx_strtrim(const char *str)
{
  if (str == NULL)
    return NULL;

  int end = mx_strlen(str), countStart = 0, countEnd = 0;

  for (int i = 0; i < end; i++)
  {
    if (mx_isspace(str[i]))
    {
      countStart++;
      continue;
    }
    break;
  }
  for (int i = end - 1; i >= 0; i--)
  {
    if (mx_isspace(str[i]))
    {
      countEnd++;
      continue;
    }
    break;
  }

  if (countStart == countEnd)
  {
    return mx_strnew(0);
  }

  char *res = mx_strnew(end - countEnd - countStart);
  return mx_strncpy(res, str + countStart, end - countEnd - countStart);
}

// int main() {

//     char name[] = "       ";
//     printf("%s\n", mx_strtrim(name));
//     return 0;
// }
