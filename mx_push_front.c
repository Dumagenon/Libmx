#include "libmx.h"

void mx_push_front(t_list **list, void *data)
{
    t_list *node = mx_create_node(data);
    if (list)
        node->next = *list;
    else
        node->next = NULL;
    *list = node;
}

// int main(){
//     // t_list *t = mx_create_node("nknknkn ");
//     // t_list *d = mx_create_node("rrrrrr ");
//     // t_list *v = mx_create_node("ttttt ");
//     // t->next = d;
//     // d->next = v;
//     t_list *t = NULL;
//     mx_push_front(&t, "iseug ");
//     while(t != 0) {
//         printf("%s", t->data);
//         t = t->next;
//     }
//     return 0;
// }
