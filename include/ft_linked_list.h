#ifndef FT_LINKED_LIST_H
#define FT_LINKED_LIST_H
typedef struct s_node 
{
	void *data;
	struct s_node *next;
}t_node;
void	foreach_list(t_node	*head, void(*f)(void *));
#endif
