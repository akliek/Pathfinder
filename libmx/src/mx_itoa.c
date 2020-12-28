#include "libmx.h"

char *mx_itoa (int number) {
    int len = 1;
    int tmp = number;
    char *str = NULL;

    if (number == INT_MIN)
        return "-2147483648";
    if (number < 0) {
        number *= -1;
        len++;
    }
    else if (number == 0)
        return "0";
    for (int tmp1 = number; tmp1 > 0; len++)
        tmp1 /= 10;
    str = mx_strnew(len);
    for (len -= 1; len > 0;  number /= 10)
        str[--len] = number % 10 + '0';
    if (tmp < 0)
        str[0] = '-';
    return str;
}
