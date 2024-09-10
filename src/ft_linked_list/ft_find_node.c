#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*ft_find_node(t_node *head, void *data, int (*eq)(void *d1, void *d2))
{
	t_node	*current;

	current = head;
	while (current != NULL && !eq(data, current->data))
	{
		current = current->next;
	}
	return (current);
}
