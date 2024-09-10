#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*ft_insert_after(t_node *node, void *data)
{
	t_node *new_node;

	if(node == NULL)
		return NULL;
	new_node = (t_node *)malloc(sizeof(t_node));
	if(new_node == NULL)
		return NULL;
	new_node->next = node->next;
	new_node->data = data;
	node->next = new_node;
	return (new_node);
}
