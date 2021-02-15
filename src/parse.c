#include "../inc/pathfinder.h"

void island_exist(int *i, char **islands, char *tmp) {
	int check = 0;

	for (int k = 0; islands[k] && k < *i; k++)
		if (mx_strcmp(islands[k], tmp) == 0)
			check++;
	if (check == 0) {
		islands[*i] = mx_strdup(tmp);
		*i += 1;
	}
}

int **create_matrix(int num, int n) {
	int **str1 = (int **)malloc(num * sizeof(int *));

	for (int i = 0; i < num; i++) {
		int *str2 = malloc(num * sizeof(int));
		for (int j = 0; j < num; j++)
			str2[j] = n;
		str1[i] = str2;
	}
	return str1;
}

t_islands parse(int fd, int islands_num) {
	int i = 0;
	int j = 2;
	char *line;
	t_islands island;
	int index1, index2;
	island.matrix = create_matrix(islands_num, 0);
	island.names = (char **)malloc((islands_num) * sizeof(char *));

	while (mx_read_line(&line, 1, '\n', fd) > 0) {
		line = mx_replace_substr(line, ",", "-");
		char **lines = mx_strsplit(line, '-');
		island_exist(&i, island.names, lines[0]);
		island_exist(&i, island.names, lines[1]);
		for (int j = 0; j < i; j++) {
			if (mx_strcmp(island.names[j], lines[0]) == 0)
				index1 = j;
			if (mx_strcmp(island.names[j], lines[1]) == 0)
				index2 = j;
		}
		if (mx_strcmp(lines[0], lines[1]) == 0) {
			mx_printerr("error: line ");
			mx_printint(j);
			mx_printerr(" is not valid\n");
			exit(1);
		}
		j++;
		island.matrix[index1][index2] = mx_atoi(lines[2]);
		island.matrix[index2][index1] = mx_atoi(lines[2]);
		mx_strdel(&line);
		mx_del_strarr(&lines);
	}
	if (i != islands_num) {
		mx_printerr("error: invalid number of islands\n");
		exit(1);
	}
	island.names[i] = NULL;
	return island;
}
