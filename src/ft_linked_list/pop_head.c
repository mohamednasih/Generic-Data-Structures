#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*pop_head(t_node **a_head)
{
	t_node	*head;

	head = *a_head;
	if (head)
	{
		*a_head = head->next;
	}
	return (head);
}
