#include "libmx.h"

// bool strcmp_my(void *s1, void *s2)
// {
//     return mx_strcmp(s1, s2) > 0 ? true : false;
// }

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (lst == NULL)
        return NULL;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (t_list *tmp = lst; tmp->next; tmp = tmp->next)
        {
            if (cmp(tmp->data, tmp->next->data))
            {
                t_list *temp = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = temp;
                flag = 1;
            }
        }
    }
    return lst;
}

// int main()
// {
//     t_list *node = mx_create_node("fdsafdsa");
//     mx_push_front(&node, "Hello");
//     mx_push_back(&node, "1");
//     mx_push_back(&node, "2");
//     mx_push_back(&node, "C");
//     mx_push_back(&node, "1");
//     mx_push_back(&node, "2");
//     mx_push_back(&node, "3");
//     // t_list *node2 = NULL;
//     // mx_pop_front(&node);
//     // mx_pop_back(&node);
//     t_list *current = node;
//     printf("size = %d\n", mx_list_size(node));
//     for (int i = 0; i < mx_list_size(node); i++)
//     {
//         printf("| %s\n", current->data);
//         current = current->next;
//     }
//     printf("sort\n");

//     current = mx_sort_list(node, strcmp_my);
//     while (current)
//     {
//         printf("| %s\n", current->data);
//         current = current->next;
//     }
// }
