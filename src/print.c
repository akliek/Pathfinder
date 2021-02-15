#include "../inc/pathfinder.h"

int *print_routes(int *route, int j, char **names, int *sum_dists) {
	if (route[j] == -1)
		return 0;
	print_routes(route, route[j], names, sum_dists);
	mx_printstr(" -> ");
	mx_printstr(names[j]);
	for (int i = 0; i < 5; i++)
		if (sum_dists[i] == 0) {
			sum_dists[i] = j;
			break;
		}
	return sum_dists;
}

void print(int islands_num, int fd) {
	t_islands island = parse(fd, islands_num);
	t_out *out[islands_num];
	for (int i = 0; i < islands_num; i++)
		out[i] = algorithm(island.matrix, i, islands_num);

	for (int i = 0; i < islands_num; i ++) {
		for (int j = 2; j < islands_num; j++) {
			for (int b = 0; b < 40; b++)
				mx_printchar('=');
			mx_printchar('\n');
			int sum[5];
			for (int k = 0; k < 5; k++)
				sum[k] = 0;
			mx_printstr("Path: ");
			mx_printstr(island.names[i]);
			mx_printstr(" -> ");
			mx_printstr(island.names[j]);
			mx_printstr("\nRoute: ");
			mx_printstr(island.names[i]);
			int *sum_dists = print_routes(out[i]->route, j, island.names, sum);
			mx_printstr("\nDistance: ");
			if (sum_dists[0] != 0 && sum_dists[0] != j) {
				mx_printint(island.matrix[i][sum_dists[0]]);
				mx_printstr(" + ");
				for (int k = 1; k < 5 && sum_dists[k] && sum_dists[k] != 0; k++) {
					mx_printint(island.matrix[sum_dists[k - 1]][sum_dists[k]]);
					if (sum_dists[k + 1] != 0)
						mx_printstr(" + ");
				}
				mx_printstr(" = ");
			}
			mx_printint(out[i]->dist[j]);
			mx_printchar('\n');
			for (int b = 0; b < 40; b++)
				mx_printchar('=');
			mx_printchar('\n');
			sum_dists = NULL;
		}
		free(out[i]);
		out[i] = NULL;
	}
}
