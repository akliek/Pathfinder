#include "libmx.h"

char *mx_file_to_str(const char *filename) {
    int file = open(filename, O_RDONLY);
    int len = 0;
    char buf;
    char *str;

    if (file > 0) {
        while ((read(file, &buf, 1)))
            len++;
        close(file);
        if (len > 0) {
            file = open(filename, O_RDONLY);
            str = mx_strnew(len);
            for (int i = 0; read(file, &buf, 1); i++)
                str[i] = buf;
            close(file);
            return str;
        }
    }
    return NULL;
}
