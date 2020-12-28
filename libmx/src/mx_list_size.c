#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *tmp = list;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return i;
}
