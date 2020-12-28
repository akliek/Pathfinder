#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    char **str;
    int j = 0;
    int len = 0;
    int key = 0;

    if (!s)
        return NULL;
    str = malloc(sizeof(char *) * mx_count_words(s, c) + 1);
    for (int i = 0; s[i]; i++) {
        if (s[i] != c && len++ == 0)
            key = i;
        if (len > 0 && (s[i + 1] == c || s[i + 1] == 0)) {
            str[j] = mx_strnew(len);
            str[j] = mx_strncpy(str[j], &s[key], len);
            len = 0;
            j++;
        }
    }
    str[j] = NULL;
    return str;
}
