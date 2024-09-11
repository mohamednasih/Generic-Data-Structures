#include <stdlib.h>
#include "ft_linked_list.h"

void	ft_prepend_node(t_node **head, t_node *new_node)
{
	if (new_node == NULL)
		return ;
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
