#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *dst1 = dst;
    unsigned const char *src1 = src;

    char *tmp = (char *)malloc(sizeof(char) * len);
    if (tmp == NULL)
        return NULL;
    else {
       for (unsigned int i = 0; i < len; i++)
           *(tmp + i) = *(src1 + i);
       for (unsigned int i = 0; i < len; i++)
           *(dst1 + i) = *(tmp + i);
       free(tmp);
    }
    return dst;
}
