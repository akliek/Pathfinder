#include "libmx.h"

char *mx_strdup(const char *str) {
    char *p = mx_strnew(mx_strlen(str));
    mx_strcpy(p, str);
    return p;
}
