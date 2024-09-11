#include <stdlib.h>
#include "ft_linked_list.h"

void	free_nodes(t_node	* head)
{
	t_node	*to_free;

	while (head)
	{
		to_free = head;
		head = head->next;
		free(to_free);
	}
}
