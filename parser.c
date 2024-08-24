#include "include/parser.h"
#include "include/map.h"
#include "include/string_utils.h"
#include <stdlib.h>

int add_new_edge(t_map **map, unsigned int v1, unsigned int v2) {
    if (append_new_map_node(map, v1))
        return (-1);
    if (append_new_map_node(map, v2))
        return (-1);
    if (append_new_adj(map, v1, v2))
        return (-1);
    if (append_new_adj(map, v2, v1))
        return (-1);
    return (0);
}

int    parse_graph(t_map **map, char **vector) {
    char    *current;
    char    *first;
    char    *second;
    int     index;
    int     v_ind;

    v_ind = 0;
    current = vector[v_ind];
    while (current) {
        index = index_of(current, '-');
        if (index == -1) {
            free_map(map);
            return (-1);
        }
        first = ft_substr(current, 0, index);
        second = ft_substr(current, index + 1, ft_strlen(current));
        if ((!first || !second) || add_new_edge(map, ft_abs_atoi(first), ft_abs_atoi(second))) {
            free_map(map);
            free(first);
            free(second);
            return (-1);
        }
        free(first);
        free(second);
        current = vector[++v_ind];
    }
    return (0);
}
