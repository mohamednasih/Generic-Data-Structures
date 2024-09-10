#include <stdlib.h>
#include "ft_linked_list.h"

t_node	*insert_after_data(t_node *head, void *target, int (*eq)(void *d, void *d1), void *new_data)
{
	t_node	*node;

	node = ft_find_node(head, target, eq);
	if (node ==  NULL)
	{
		return (NULL);
	}	
	return (ft_insert_after(node, new_data));
}
