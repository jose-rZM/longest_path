#include "../include/parser.h"
#include "../include/map.h"
#include "../include/string_utils.h"
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

int parse_numeric_substring(char *str, int start, int end) {
    char *sub;
    int parsed;
    if (!ft_substr_is_numeric(str, start, end))  {
       return (-1);
    }
    sub = ft_substr(str, start, end);
    parsed = ft_abs_atoi(sub);
    free(sub);
    return (parsed);
}

int    parse_graph(t_map **map, char **vector) {
    char    *current;
    int     first;
    int     second;
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
        first = parse_numeric_substring(current, 0, index);
        second = parse_numeric_substring(current, index + 1, ft_strlen(current));
        if (first == -1 || second == -1 || add_new_edge(map, first, second)) {
            free_map(map);
            return (-1);
        }
        current = vector[++v_ind];
    }
    return (0);
}
