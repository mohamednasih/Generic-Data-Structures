#include "ft_dlinked_list.h"

void	free_dlist(t_dlist list)
{
	t_dnode	*current;
	t_dnode *tmp;

	if (list.destroy == NULL)
		return ;
	current = list.head;
	while(current)
	{
		tmp = current;
		current = current->next;
		list.destroy(tmp);
	}
}
