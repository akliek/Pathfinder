#include "libmx.h"

int mx_atoi(char *str) {
	int result = 0;
	int neg_multiplier = 1;

	// Scrub leading whitespace
	while (*str && ( (*str == ' ') || (*str == '\t')))
		str++;

	// Check for negative
	if (*str && *str == '-') {
		neg_multiplier = -1;
		str++;
	}

	// Do number
	for (; *str && mx_isdigit(*str); str++) {
		result = (result * 10) + (*str - '0');
	}
	return result * neg_multiplier;
}
