#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *newdst = dst;
    const unsigned char *newsrc = src;
    size_t i;

    for (i = 0; i < n; i++) {
        newdst[i] = newsrc[i];
        if (newdst[i] == (unsigned char) c)
            return &((unsigned char*)dst)[i + 1];
    }
    return NULL;
}
