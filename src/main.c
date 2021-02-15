#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	char *line;
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY);
//	validation(argv, fd);
	mx_read_line(&line, 1, '\n', fd);
	int islands_num = mx_atoi(line);
	mx_strdel(&line);
	print(islands_num, fd);
}
