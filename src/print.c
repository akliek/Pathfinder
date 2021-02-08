#include "../inc/pathfinder.h"

void print_routes(int *parent, int j, char **names) {
	if (parent[j] == -1)
		return;
	print_routes(parent, parent[j], names);
	mx_printstr(" -> ");
	mx_printstr(names[j]);
}

void print(int islands_num, int fd) {
	t_islands island = parse(fd, islands_num);

	for (int i = 0; i < islands_num; i ++) {
		t_out *out = algorithm(island.matrix, i, islands_num);
		for (int j = i + 1; j < islands_num; j++) {
			mx_printstr("Path: ");
			mx_printstr(island.names[i]);
			mx_printstr(" -> ");
			mx_printstr(island.names[j]);
			mx_printstr("\nRoute: ");
			mx_printstr(island.names[i]);
			print_routes(out->parent, j, island.names);
			mx_printstr("\nDistance: ");
			mx_printint(out->dist[j]);
			mx_printstr("\n\n");
		}
		free(out->dist);
		out->dist = NULL;
		free(out->parent);
		out->parent = NULL;
		free(out);
		out = NULL;
	}
}
