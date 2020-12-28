#include "pathfinder.h"

void island_init(t_island *island_n, t_list *map, char **lines) {
	t_island island;

	if (!island_n) {
		island.island_name = lines[0];
		island.checked = 0;
		island.shortest_dist = -1;
		island.route = NULL;
		mx_push_back(map, &island);
	}
}

t_list *find_by_name(t_list *map, const char *island_name) {
	while(map->next) {
        t_island *island = (t_island*)malloc(sizeof(t_island));
	    island = map->data;
		if (mx_strcmp(island_name, island_name) == 0)
			return NULL;
		map = map->next;
		free(&island);
	}
	return map;
}

void parse_line(t_list *map, char *line) {
	char 		**lines;
	t_island	*island1;
	t_island	*island2;
	t_link		link;

	line = mx_replace_substr(line, ",", "-");
	lines = mx_strsplit(line, '-');
	island1 = (t_island*)find_by_name(map, lines[1]);
	island_init(island1, map, lines);
	link.island = find_by_name(map, lines[0]);
	link.dist = (int)lines[2];
	mx_push_back(island1->route, &link);
    free(link.island->data);
    island2 = (t_island*)find_by_name(map, lines[0]);
    island_init(island2, map, lines);
	link.island = find_by_name(map, lines[1]);
	link.dist = (int)lines[2];
	mx_push_back(island2->route, &link);
    free(link.island->data);
}
void start_reading(int fd) {
	char		*line;
	t_list		*map;

	if (mx_read_line(&line, 1, '\n', fd) > 0) {
		map = (t_list *)malloc(sizeof(t_list));
		while (mx_read_line(&line, 1, '\n', fd) > 0) {
		    if (mx_strlen(line) == 1)
				continue;
			parse_line(map, line);
		}
	}
}

