#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    size_t i = 0;

    while (i < n && str[i] != c)
        i++;
    if (c == str[i])
        return (char*) s + i;
    return NULL;
}
