#include "pathfinder.h"

int main(int argc, char **argv) {
    head = NULL;
	int fd = open(argv[1], O_RDONLY);
	start_reading(fd);
	return 0;
}
