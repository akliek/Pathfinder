#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    size_t i = mx_strlen(s);
    size_t j = 0;

    while (j < n && str[--i] != c)
        j++;
    if (c == str[i])
        return (char*) s + i;
    return NULL;
}
