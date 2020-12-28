#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **arr_del = *arr;

    while (*arr_del)
        mx_strdel(arr_del++);
    free(*arr);
    *arr = NULL;
}
