#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;
    size_t i = 0;

    while (str1[i] == str2[i])
        i++;
    if (i < n)
        return str1[i] - str2[i];
    return 0;
}
