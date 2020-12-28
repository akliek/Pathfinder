#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *begin = mx_create_node(data);

    if (*list == NULL)
        *list = begin;
    else {
        begin->next = *list;
        *list = begin;
    }
}
