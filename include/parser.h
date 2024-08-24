#ifndef PARSER_H
# define PARSER_H

struct s_map;
typedef struct s_map t_map;

int     add_new_edge(t_map **map, unsigned int v1, unsigned int v2);
int     parse_numeric_substring(char *str, int start, int end);
int     parse_graph(t_map **map, char **vector);
#endif