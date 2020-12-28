#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	int i = 0;
	char *temp =(char*) str;

	if (str == NULL | sub == NULL)
		return -1;
	if (mx_strlen(sub) == 0)
		return 0;
	while ((temp = mx_strstr(temp, sub)) != NULL) {
		temp += mx_strlen(sub);
		i++;
	}
	return i;
}
