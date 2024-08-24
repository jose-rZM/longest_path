#ifndef MAP_H
#define MAP_H

// FwD
struct s_list;
typedef struct s_list t_list;

typedef	struct s_map t_map;
struct	s_map
{
	unsigned int   vertex;
	t_list         *adjacents;
	t_map          *next;
};

t_map   *create_new_map_node(unsigned int vertex);
int     append_new_map_node(t_map **map, unsigned int vertex);
void    free_map(t_map **map);
int     append_new_adj(t_map **map, unsigned int first, unsigned int adj);
t_map   *get_map_node(t_map *map, unsigned int vertex);
#endif
