#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int count = 0;
    unsigned long temp;
    char *result = NULL;

    if (nbr == 0) {
        result = mx_strnew(1);
        result[0] = '0';
        return result;
    }
    for (temp = nbr; temp > 0; temp /= 16)
        count++;
    result = mx_strnew(count);
    for (temp = nbr; temp > 0; temp /= 16) {
        count--;
        if (temp % 16 > 9)
            result[count] = temp % 16 + 87;
        else
            result[count] = temp % 16 + 48;
    }
    return result;
}
