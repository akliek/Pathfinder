#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr;
    size_t n_size;

    if ((int)size < 0)
        return NULL;
    n_size = malloc_size(ptr);
    if (size != 0 && n_size >= size)
        return ptr;
    new_ptr = malloc(size);
    if (ptr != NULL && size != 0)
        new_ptr = mx_memcpy(new_ptr, ptr, n_size);
    free(ptr);
    return new_ptr;
}
