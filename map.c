#include <stdlib.h>
#include "include/map.h"
#include "include/list.h"

t_map   *create_new_map_node(unsigned int vertex) {
    t_map   *node;

    node = (t_map *) malloc(sizeof(t_map));
    if (!node)
        return (NULL);
    node->vertex = vertex;
    node->adjacents = NULL;
    node->next = NULL;
    return (node);
}

int   append_new_map_node(t_map **map, unsigned int vertex) {
    t_map   *node;
    t_map   *current;

    if (*map && already_in_map(*map, vertex)) {
        return (0);
    }

    node = create_new_map_node(vertex);
    if (!node)
        return (-1);
    if (!*map)
        *map = node;
    else {
       current = *map;
       while (current->next) {
           current = current->next;
        }
        current->next = node;
    }
    return (0);
}

void    free_map(t_map **map) {
    t_map   *tmp;

    while (*map) {
        tmp = *map;
        *map = (*map)->next;
        free_list(&tmp->adjacents);
        free(tmp);
    }
}

int     append_new_adj(t_map **map, unsigned int first, unsigned int adj) {
    t_map   *node;

    node = already_in_map(*map, first);
    if (!node)
        return (-1);
    append_new_node(&node->adjacents, adj);
    return (0);
}

t_map     *already_in_map(t_map *map, unsigned int vertex) {
    while (map) {
        if (map->vertex == vertex) {
            return (map);
        }
        map = map->next;
    }
    return (map);
}