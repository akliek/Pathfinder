#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp = mx_strnew(mx_strlen(str));
    char *res = NULL;
    int j = 0;

    if(!str)
        return NULL;
    for (int i = 0; str[i]; i++) {
        if (mx_isspace(str[i]) == 0) {
            temp[j] = str[i];
            j++;
        }
        if (mx_isspace(str[i]) == 0 && mx_isspace(str[i + 1]) == 1) {
            temp[j] = ' ';
            j++;
        }
    }
    res = mx_strtrim(temp);
    mx_strdel(&temp);
    return res;
}
