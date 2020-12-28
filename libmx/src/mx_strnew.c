#include "libmx.h"

char *mx_strnew(const int size) {
    char *p;

    if (size < 0)
        return NULL;
    p = malloc(size + 1);
    for (int i = 0; i <= size; i++)
        p[i] = '\0';
    return p;
}
