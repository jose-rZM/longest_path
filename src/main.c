#include <stdlib.h>
#include "../include/string_utils.h"
#include "../include/parser.h"
#include "../include/map.h"
#include "../include/list.h"

void free_vector(char **vector) {
    int i;

    i = 0;
    while (vector[i]) {
        free(vector[i]);
        i++;
    }
    free(vector);
}

int ft_max(int a, int b) {
    if (a >= b) {
        return (a);
    }
    else {
        return (b);
    }
}

int dfs(t_map *graph, t_map *current, t_list **visited) {
    t_list  *adjs;
    int     max_len;

    append_new_node(visited, current->vertex);
    adjs = current->adjacents;
    max_len = 0;
    while (adjs) {
        if (!list_contains_node(*visited, adjs->data)) {
            max_len = ft_max(max_len, dfs(graph, get_map_node(graph, adjs->data), visited) + 1);
        }
        adjs = adjs->next;
    }
    remove_node(visited, current->vertex);
    return (max_len);
}

int longest_path(t_map *graph) {
    int     max_len;
    t_map   *current_node;
    t_list  *visited;

    max_len = 0;
    current_node = graph;
    visited = NULL;
    while (current_node) {
        max_len = ft_max(max_len, dfs(graph, current_node, &visited) + 1);
        current_node = current_node->next;
        free_list(&visited);
        visited = NULL;
    }
    return (max_len);
}

#include <stdio.h>
int main(int argc, char **argv) {
    char *str;
    char **vector;
    t_map *map;
    int max_len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <graph_representation>\n", argv[0]);
        return (1);
    }
    str = argv[1];
    map = NULL;
    max_len = 0;
    vector = ft_split(str);
    if (!vector || !vector[0]) {
        fprintf(stderr, "Error when processing input\n");
        return (1);
    }
    if (parse_graph(&map, vector) != -1) {
        max_len = longest_path(map);
        printf("Max path len: %d\n", max_len);
    } else {
        fprintf(stderr, "There was an error in parsing the graph!\n");
    }
    free_map(&map);
    free_vector(vector);
}