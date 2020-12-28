#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *s = b;


    while(len > 0) {
        *s = c;
        s++;
	    len--;
    }
    return (b);
}
