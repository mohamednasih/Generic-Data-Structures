#include <stdlib.h>
#include "ft_linked_list.h"

static t_node	*create_node(void *data)
{
	t_node *p_node;

	p_node = (t_node *)malloc(sizeof(t_node));
	p_node->data = data;
	p_node->next = NULL;
	return (p_node);
}
void	append_to_list(t_node **p_head, void *data)
{
	t_node	*current;

	if (*p_head == NULL)
	{
		*p_head = create_node(data);
		return ;
	}
	current = *p_head;
	while (current->next)
		current = current->next;
	current->next = create_node(data);
	
}
