#include "ft_dlinked_list.h"

void	foreach_dlist(t_dlist dlist, void (*f)(t_dnode *))
{
	t_dnode	*current;
	
	current = dlist.head;
	while (current)
	{
		f(current);
		current = current->next;
	}
}
