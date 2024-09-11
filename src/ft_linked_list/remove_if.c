#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*remove_if(t_node **a_head, int (*match)(void *d1))
{
	t_node	*head;
	t_node	*deleted_nodes;
	t_node	*temp;

	deleted_nodes = NULL;
	head = *a_head;
	while (head && match(head->data))
	{
		*a_head = head->next;
		temp = head;
		head = head->next;
		ft_prepend_node(&deleted_nodes, temp);
	}
	while( head && head->next)
	{
		if (match(head->next->data))
		{
			temp = head->next;
			head->next = head->next->next;
			ft_prepend_node(&deleted_nodes, temp);
		}
		else
			head = head->next;
	}
	return (deleted_nodes);
}
