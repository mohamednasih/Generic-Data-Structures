#ifndef FT_LINKED_LIST_H
#define FT_LINKED_LIST_H
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
#endif
