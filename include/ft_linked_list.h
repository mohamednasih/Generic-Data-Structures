#ifndef FT_LINKED_LIST_H
#define FT_LINKED_LIST_H
typedef struct s_node 
{
	void *data;
	struct s_node *next;
}t_node;
void	foreach_list(t_node	*head, void(*f)(void *));
void	append_to_list(t_node **head, void *data);
void	ft_prepend(t_node **head, void *data);
void    ft_insert_after(t_node *node, void *data);
#endif
