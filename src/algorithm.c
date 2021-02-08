#include "../inc/pathfinder.h"

int min_dist(int *dist, bool visited[], int islands_num) {
	int min = INT_MAX, index;

	for (int i = 0; i < islands_num; i++) {
		if (visited[i] == 0 && dist[i] <= min) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

t_out *algorithm(int **matrix, int src, int islands_num) {
	bool visited[islands_num];
	t_out *out = (t_out *)malloc(islands_num  * sizeof(t_out));
	out->dist = (int *)malloc(islands_num * sizeof(int));
	out->route = (int *)malloc(islands_num * sizeof(int));

	for(int i = src; i < islands_num; i++) {
		out->route[src] = -1;
		out->dist[i] = INT_MAX;
		visited[i] = 0;
	}
	out->dist[src] = 0;
	for (int i = src; i < islands_num; i++) {
		int m = min_dist(out->dist, visited, islands_num);
		visited[m] = 1;
		for (int j = 0; j < islands_num; j++)
			if(!visited[j] && matrix[m][j] && out->dist[m] != INT_MAX && out->dist[m] + matrix[m][j] < out->dist[j]) {
				out->route[j] = m;
				out->dist[j] = out->dist[m] + matrix[m][j];
			}
	}
	return out;
}
