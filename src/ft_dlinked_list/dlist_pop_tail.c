#include "ft_dlinked_list.h"


void	dlist_pop_tail(t_dlist *dlist)
{
	t_dnode *current;

	current = dlist->head;
	if (current == NULL)
		return ;
	if ( current && !current->next)
	{
		dlist->head = NULL;
		dlist->destroy(current);
		return ;
	}
	while(current->next)
		current = current->next;
	current->prev->next = NULL;
	dlist->destroy(current);
}
