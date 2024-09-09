#include "ft_linked_list.h"

void	foreach_list(t_node	*head, void (*f)(void *))
{
	t_node	*current;

	current = head;
	while(current)
	{
		f(current->data);
		current= current->next;
	}
}
