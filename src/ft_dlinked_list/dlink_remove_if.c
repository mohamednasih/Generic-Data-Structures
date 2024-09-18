#include "ft_dlinked_list.h"

void	dlink_remove_if(t_dlist *dlist, int (*match)(void *d1))
{
	t_dnode	*current;
	t_dnode	*tmp;

	current = dlist->head;
	while (current && match(current->data))
	{
		dlist->head = current->next;
		tmp = current;
		current = current->next;
		if (dlist->head)
			dlist->head->prev = NULL;
		dlist->destroy(tmp);
	}
	while (current && current->next)
	{
		if (match(current->next->data))
		{
			tmp = current->next;
			current->next = current->next->next;
	 		if(current->next)
				current->next->prev = current;
			dlist->destroy(tmp);
		}
		else
			current = current->next;
	}
}
