#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int least = 0;
    int greatest = size - 1;
    int mid = 0;
    int res = -1;

    while (least <= greatest) {
        (*count)++;
        mid = least + (greatest - least) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        if (mx_strcmp(arr[mid], s) < 0)
            least = mid + 1;
        if (mx_strcmp(arr[mid], s) > 0)
            greatest = mid - 1;
    }
    if (res == -1)
        (*count) = 0;
    return -1;
}
