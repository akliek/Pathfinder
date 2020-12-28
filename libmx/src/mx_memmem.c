#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const unsigned char *s1 = big;
    const unsigned char *s2 = little;

    if (big_len > little_len && (*s1 && *s2) != 0)
    for (; *s1; s1++)
        if (mx_memcmp(s1, s2, little_len) == 0)
            return (char *) s1;
    return NULL;
}
