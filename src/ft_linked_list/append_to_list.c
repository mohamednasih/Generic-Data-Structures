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
t_node	*append_to_list(t_node **p_head, void *data)
{
	t_node	*current;
	t_node	*new_node;

	new_node = create_node(data);
	if (*p_head == NULL)
	{
		*p_head = new_node;
		return (new_node);
	}
	current = *p_head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (new_node);
}
