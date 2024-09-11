#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*pop_tail(t_node **a_head)
{
	t_node	*head;
	t_node	*tail;
	
	head = *a_head;
	if (head == NULL)
		return (NULL);
	if (head && head->next == NULL)
	{
		*a_head = NULL;
		return (head);
	}
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	tail = head->next;
	head->next = NULL;
	return (tail);
}
