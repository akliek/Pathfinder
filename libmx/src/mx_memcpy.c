#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *newdst = dst;
    unsigned const char *newsrc = src;

    while (n  > 0) {
            *(newdst++) = *(newsrc++);
            --n;
    }
    return dst;
}
