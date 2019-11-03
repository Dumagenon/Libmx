#include "libmx.h"

void mx_pop_front(t_list **head)
{
    if (*head != NULL)
    {
        t_list *temp = *head, *tmp = temp->next;

        temp->data = NULL;
        free(temp);
        temp = NULL;

        *head = tmp;
    }
}

// int main()
// {
//     t_list *t = NULL;
//     // t_list *d = mx_create_node("rrrrrr ");
//     // t_list *v = mx_create_node("ttttt ");
//     // t->next = d;
//     // d->next = v;
//     mx_pop_front(&t);
//     t_list *cur = t;
//     while (cur)
//     {
//         printf("%s", cur->data);
//         cur = cur->next;
//     }
//     // mx_pop_front(&t);
//     // mx_pop_front(&t);
//     //system("leaks -q libmx");
//     return 0;
// }
