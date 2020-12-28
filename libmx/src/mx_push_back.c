#include "pathfinder.h"

//void mx_push_back(t_list **list, void *data) {
//    t_list *end = mx_create_node(data);
//    t_list *tmp = *list;
//
//    if (list == NULL) {
//        *list = end;
//        return;
//    }
//    else {
//        while (tmp->next != NULL)
//            tmp = tmp->next;
//        tmp->next = end;
//        tmp->size++;
//    }
//}

void mx_push_back(t_list *list, void *data) {
    t_list *current = list;

    if (head == NULL) {
        head = list;
        return;
    }

    current = head;

    while (current && current->next)
        current = current->next;
    current->next = (t_list *)malloc(sizeof(t_list));
    current->next->data = data;
    current->next->next = NULL;
}
