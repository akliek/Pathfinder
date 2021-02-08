#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct  s_islands {
	char        **names;
	int         **matrix;
}               t_islands;

typedef struct  s_out {
	int         *dist;
	int         *route;
}               t_out;

void validation(char **argv, int fd);
t_islands parse(int fd, int islands_num);
t_out *algorithm(int **matrix, int src, int islands_num);
void print(int island_num, int fd);

#endif
