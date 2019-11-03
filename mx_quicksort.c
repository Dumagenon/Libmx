#include "libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    int count = 0;
    if (arr == NULL)
        return -1;
    if (left < right)
    {
        int low = left, high = right;
        char *middle = arr[(low + high) / 2];
        while (low <= high)
        {
            while (mx_strlen(arr[low]) < mx_strlen(middle))
                low++;
            while (mx_strlen(arr[high]) > mx_strlen(middle))
                high--;
            if (low <= high)
            {
                if (mx_strlen(arr[low]) != mx_strlen(arr[high]))
                {
                    count++;
                    char *tmp = arr[low];
                    arr[low] = arr[high];
                    arr[high] = tmp;
                }
                low++;
                high--;
            }
        }
        count += mx_quicksort(arr, left, high);
        count += mx_quicksort(arr, low, right);
    }
    return count;
}

// int main() {
//   char *arr[] = {"1", "22","88888888", "666666", "333", "4444", "7777777", "999999999", "55555"};//{"666666", "333", "999999999", "1", "88888888", "4444", "55555", "7777777", "22"};
//   printf("%d\n", mx_quicksort(arr, 0, 8));
//   for(int i = 0; i < 9;i++) {
//     printf("%s\n", arr[i]);
//   }
//   return 0;
// }
