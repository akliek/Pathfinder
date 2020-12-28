#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct		s_link {
	int				dist;
	struct s_list	*island;
}					t_link;

typedef struct		s_island {
	char			*island_name;
	t_list			*route;
	bool			checked;
	int 			shortest_dist;
}					t_island;

t_list *head;

t_list	*find_by_name(t_list *map, const char *island_name);
void    island_init(t_island *island_n, t_list *map, char **lines);
void	parse_line(t_list *map, char *line);
void	start_reading(int fd);

#endif
