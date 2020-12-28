#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_strlen(s1);
    char *str = NULL;

    if (len < n)
        str = mx_strdup(s1);
    else {
	    str = mx_strnew(n);
	    str = mx_strncpy(str, s1, n);
    }
    return str;
}
