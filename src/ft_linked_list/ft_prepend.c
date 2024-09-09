#include <stdlib.h>
#include "ft_linked_list.h"
void	ft_prepend(t_node **head, void *data)
{
	t_node	*new_node = (t_node *)malloc(sizeof(t_node));	
	new_node->data = data;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}
