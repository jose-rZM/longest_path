#include <stdlib.h>
#include "../include/list.h"

t_list *create_new_node(unsigned int data) {
    t_list  *node;

    node = (t_list *) malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

int append_new_node(t_list **list, unsigned int data) {
    t_list  *new_node;
    t_list  *current;

    new_node = create_new_node(data);
    if (!new_node) {
        return (-1);
    }
    if (!*list) {
        *list = new_node;
    } else {
        current = *list;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    return (0);
}

int     remove_node(t_list **list, unsigned int data) {
    t_list  *prev;
    t_list  *current;

    prev = NULL;
    current = *list;
    while (current && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (!current) {
        return (-1);
    }
    if (!prev) {
       *list = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
    return (0);
}

int     list_contains_node(t_list *list, unsigned int data) {
    if (!list)
        return (0);
    while (list && list->data != data) {
        list = list->next;
    }
    return (list != NULL);
}

void free_list(t_list **list) {
    t_list  *temp;

    while (*list) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}
