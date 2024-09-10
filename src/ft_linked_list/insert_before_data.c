#include <stdlib.h>
#include "ft_linked_list.h"
#include <stdio.h>
t_node	*insert_before_data(t_node **a_head, void *target, int (*eq)(void *d, void *d1), void *new_data)
{
	t_node	*node;
	t_node	*head;	

	head = *a_head;
	if (head && eq(target, head->data))
	{
		node = (t_node *)malloc(sizeof(t_node));
		*a_head = node;
		node->next = head;	
		node->data = new_data;
		return (node);
	}
	while (head && head->next && !eq(target, head->next->data))
	{
		head = head->next;
	}
	if (head && head->next)
		return (ft_insert_after(head, new_data));
	return (NULL);
}
