#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *pop = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        pop = *head;
        while (pop->next->next != NULL)
            pop = pop->next;
        free(pop->next);
        pop->next = NULL;
    }
}
