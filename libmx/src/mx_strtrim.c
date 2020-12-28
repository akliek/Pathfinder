#include "libmx.h"

char *mx_strtrim(const char *str) {
	char *s = NULL;
    int length;

    if (!str)
        return NULL;
    while (mx_isspace(*str))
    	str++;
    length = mx_strlen(str);
    for (int i = length - 1;  mx_isspace(str[i]); i--)
    	length--;
    if (length < 0) {
    	s = mx_strnew(0);
    	return s;
    }
    s = mx_strnew(length);
    s = mx_strncpy(s, str, length);
    return s;
}
