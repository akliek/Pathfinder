#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char arr_byte[4];
	int size = 0;

    if (c <= 127) {
	    arr_byte[0] = c;
	    size = 1;
    }
    else if (c >= 128 && c < 2048) {
        arr_byte[0] = (c >> 6) + 0xC0;
        arr_byte[1] = (c & 0x3F) + 0x80;
		size = 2;
    }
    else if (c >= 2048 && c < 65536) {
        arr_byte[0] = (c >> 12) + 0xE0;
        arr_byte[1] = ((c >> 6) & 0x3F) + 0x80;
        arr_byte[2] = (c & 0x3F) + 0x80;
		size = 3;
    }
    else if (c < 1112064){
        arr_byte[0] = (c >> 18) + 0xF0;
        arr_byte[1] = ((c >> 12) & 0x3F) + 0x80;
        arr_byte[2] = ((c >> 6) & 0x3F) + 0x80;
        arr_byte[3] = (c & 0x3F) + 0x80;
        size = 4;
    }
    else
    	return;
    write(1, arr_byte, size);
}
