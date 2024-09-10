#include <stdlib.h>
#include "ft_linked_list.h"

void	ft_insert_after(t_node *node, void *data)
{
	t_node *new_node;

	if(node == NULL)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if(new_node == NULL)
		return ;
	new_node->next = node->next;
	new_node->data = data;
	node->next = new_node;
}
