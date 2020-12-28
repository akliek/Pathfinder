#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *res;
    int i, count = 0;

    if (str == NULL | sub == NULL | replace == NULL)
    	return NULL;
    for (i = 0; str[i]; i++)
        if (strstr(&str[i], sub) == &str[i]) {
            count++;
            i += mx_strlen(sub) - 1;
    }
    res = (char*)malloc(i + count * (mx_strlen(replace) - mx_strlen(sub)) + 1);
    i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&res[i], replace);
            i += mx_strlen(replace);
            str += mx_strlen(sub);
        }
        else
            res[i++] = *str++;
    }
    res[i] = '\0';
    return res;
}
