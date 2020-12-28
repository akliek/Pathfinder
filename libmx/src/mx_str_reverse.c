#include "libmx.h"

void mx_str_reverse(char *s) {
	int b;
	int e = mx_strlen(s) - 1;

	for (b = 0; b <= e; b++) {
		mx_swap_char(&s[b], &s[e]);
		e--;
	}
}
