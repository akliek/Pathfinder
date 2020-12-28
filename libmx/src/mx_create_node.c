#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *head = NULL;

    if (data == NULL)
        return NULL;
    else {
        head = (t_list*)malloc(sizeof(t_list));
        head->data = data;
        head->next = NULL;
        return head;
    }
}
