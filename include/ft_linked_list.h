#ifndef FT_LINKED_LIST_H
#define FT_LINKED_LIST_H
#include "ft_types.h"

typedef struct s_node 
{
	void *data;
	struct s_node *next;
}t_node;
void	foreach_list(t_node	*head, void(*f)(void *));
t_node	*append_to_list(t_node **head, void *data);
t_node	*ft_prepend(t_node **head, void *data);
t_node	*ft_insert_after(t_node *node, void *data);
t_node	*ft_find_node(t_node *head, void *data, int (*eq)(void *d1, void *d2));
t_node	*insert_after_data(t_node *head, void *target, int (*eq)(void *d, void *d1), void *new_data);
t_node	*insert_before_data(t_node **head, void *target, int (*eq)(void *d, void *d1), void *new_data);
void	ft_prepend_node(t_node **head, t_node *new_node);
void	free_list(t_node *head);
void	free_nodes(t_node *head);
t_node  *array_to_linked_list(void *buffer, t_size size, t_size el_size);
t_node  *pop_head(t_node **a_head);
t_node	*pop_tail(t_node **a_head);
t_node	*remove_if(t_node **a_head, int (*match)(void *d1));
#endif
