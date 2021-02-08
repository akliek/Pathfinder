#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	char *line;
	int fd = open(argv[1], O_RDONLY);
	mx_read_line(&line, 1, '\n', fd);
	int islands_num = mx_atoi(line);
	print(islands_num, fd);

	mx_strdel(&line);
}
