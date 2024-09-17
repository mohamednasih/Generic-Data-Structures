#include "ft_dlinked_list.h"

void	dlist_pop_head(t_dlist *dlist)
{
	t_dnode	*head;

	head = dlist->head;
	if (head)
	{
		dlist->head =  head->next;
		dlist->destroy(head);
	}
	if (dlist->head)
		dlist->head->prev = NULL;

}
