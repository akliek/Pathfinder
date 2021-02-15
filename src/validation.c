#include "../inc/pathfinder.h"

void file_empty(char **argv, int fd) {
	char *buf = mx_strnew(1);
	int content = read(fd, buf, 1);

	if (content == 0) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" is empty\n");
		exit(1);
	}
	mx_strdel(&buf);
}

void file_exist (char **argv, int fd) {
	if (fd < 0) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" does not exist\n");
		exit(1);
	}
}

void first_line_invalid(char *content) {
	for (int i = 0; content[i] != '\n'; i++)
		if (mx_isdigit(content[i]) == 0) {
			mx_printchar(content[i]);
			mx_printerr("error: line 1 is not valid\n");
			exit(1);
		}
}

void erroor_message(int line_num) {
	mx_printerr("error: line ");
	mx_printint(line_num);
	mx_printerr(" is not valid\n");
	exit(1);
}

void line_invalid(char *content) {
	int i;
	int line_num = 2;

	for (i = 0; content[i] != '\n'; i++);
	for (i += 2; content[i] != '\0'; i++ && line_num++) {
		for (; content[i] != '-'; i++)
			if (mx_isalpha(content[i]) == 0)
				erroor_message(line_num);
		for (i += 1; content[i] != ','; i++)
			if (mx_isalpha(content[i]) == 0)
				erroor_message(line_num);
		for (i += 1; content[i] != '\n'; i++)
			if (!mx_isdigit(content[i]))
				erroor_message(line_num);
	}
}

void validation(char **argv, int fd) {
	char *content = mx_file_to_str(argv[1]);
	file_empty(argv, fd);
	file_exist(argv, fd);
	first_line_invalid(content);
	line_invalid(content);
	mx_strdel(&content);
	close(fd);
}
