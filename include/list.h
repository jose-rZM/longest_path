#ifndef LIST_H
#define LIST_H
typedef struct s_list t_list;

struct	s_list
{
	unsigned int       data;
	t_list             *next;
};

t_list  *create_new_node(unsigned int data);
int     append_new_node(t_list **list, unsigned int data);
int     remove_node(t_list **list, unsigned int data);
int     list_contains_node(t_list *list, unsigned int data);
void    free_list(t_list **list);
#endif
