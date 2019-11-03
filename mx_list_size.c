#include "libmx.h"

int mx_list_size(t_list *list)
{
    int i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return i;
}

// int main(){
//     t_list *t = mx_create_node("nknknkn ");
//     t_list *d = mx_create_node("rrrrrr ");
//     t_list *v = mx_create_node("ttttt ");
//     t->next = d;
//     d->next = v;
//     printf("List size is %d", mx_list_size(t));
//     return 0;
// }
