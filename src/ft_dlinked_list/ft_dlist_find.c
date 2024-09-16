#include "ft_dlinked_list.h"

t_dnode	*ft_dlist_find(t_dlist list, void *target, int (*eq)(void *data1, void *data2))
{
	t_dnode	*current;

	current = list.head;
	while (current && !eq(target, current->data))
		current=current->next;
	return (current);
}
