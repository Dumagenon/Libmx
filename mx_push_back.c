#include "libmx.h"

void mx_push_back(t_list **list, void *data)
{
    if (*list == NULL)
    {
        t_list *node = mx_create_node(data);
        *list = node;
    }
    else
    {
        t_list *node = mx_create_node(data), *p = *list;
        while (p->next)
            p = p->next;
        p->next = node;
    }
}

// int main()
// {
//     // t_list *t = mx_create_node("nknknkn ");
//     // t_list *d = mx_create_node("rrrrrr ");
//     // t_list *v = mx_create_node("ttttt ");
//     // t->next = d;
//     // d->next = v;
//     t_list *t = NULL;
//     mx_push_back(&t, "iseug ");
//     while (t)
//     {
//         printf("%s", t->data);
//         t = t->next;
//     }
//     return 0;
// }
