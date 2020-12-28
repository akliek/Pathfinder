#include "libmx.h"

static int mx_new_line(char **str, char **lineptr, int fd, char delim, int result_read, size_t buf_size) {
	char *tmp;
	int len = 0;

	while (str[fd][len] != delim && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == delim) {
		*lineptr = mx_substr(str[fd], 0, len);
		tmp = mx_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][len] == '\0') {
		if (result_read == (int)buf_size)
			return (mx_read_line(lineptr, buf_size, delim, fd));
		*lineptr = mx_strdup(str[fd]);
		free (str[fd]);
	}
	return len;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	static char *str[225];
	char buf[buf_size + 1];
	char *tmp;
	int result_read;

	if(fd < 0)
		return -2;
	while((result_read = read(fd, buf, buf_size)) > 0) {
		buf[result_read] = '\0';
		if(str[fd] == NULL)
			str[fd] = mx_strnew(1);
		tmp = mx_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if(mx_strchr(buf, delim))
			break;
	}
	if(result_read < 0)
		return -1;
	if(result_read == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return 0;
	return (mx_new_line(str, lineptr, fd, delim, result_read, buf_size));
}
