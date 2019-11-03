#include "libmx.h"

void mx_pop_back(t_list **head)
{
    if (*head != NULL)
    {
        t_list *p = *head;
        if (p->next == NULL)
        {
            p->data = NULL;
            free(p);
        }
        else
        {
            while (p->next->next)
                p = p->next;
            p->next->data = NULL;
            free(p->next);
            p->next = NULL;
        }
    }
}

// int main()
// {
//     t_list *t = NULL;
//     // t_list *d = mx_create_node("rrrrrr ");
//     // t_list *v = mx_create_node("ttttt ");
//     // t->next = d;
//     // d->next = v;
//     mx_pop_back(&t);
//     t_list *cur = t;
//     while (cur)
//     {
//         printf("%s", cur->data);
//         cur = cur->next;
//     }
//     //mx_pop_back(&t);
//     //mx_pop_back(&t);
//     //system("leaks -q libmx");
//     return 0;
// }
