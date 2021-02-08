#include "../inc/pathfinder.h"

int *print_routes(int *parent, int j, char **names, int *sum_dists) {
	if (parent[j] == -1)
		return 0;
	print_routes(parent, parent[j], names, sum_dists);
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

	for (int i = 0; i < islands_num; i ++) {
		t_out *out = algorithm(island.matrix, i, islands_num);
		for (int j = i + 1; j < islands_num; j++) {
			int sum[5];
			for (int k = 0; k < 5; k++)
				sum[k] = 0;
			mx_printstr("Path: ");
			mx_printstr(island.names[i]);
			mx_printstr(" -> ");
			mx_printstr(island.names[j]);
			mx_printstr("\nRoute: ");
			mx_printstr(island.names[i]);
			int *sum_dists = print_routes(out->route, j, island.names, sum);
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
			mx_printint(out->dist[j]);
			mx_printstr("\n\n");
		}
	}
}
