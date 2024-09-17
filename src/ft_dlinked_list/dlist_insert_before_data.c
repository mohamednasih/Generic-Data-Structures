#include "ft_dlinked_list.h"

t_dnode	*dlist_insert_before_match(t_dlist *list,int (*match)(void *d1, void *d2), void *data)
{
	t_dnode	*current;
	t_dnode	*new_node;
	
	current = list->head;
	if (!current || (current && match(current->data, data)))
		return ft_dlist_prepend(list, data);
	new_node = (t_dnode *)malloc(sizeof(t_dnode));
	new_node->data = data;
	if (new_node == NULL)
		return (new_node);
	while (current->next && !match(current->next->data, data))
		current = current->next;
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next)
		current->next->prev = new_node;
	current->next = new_node;
	return (new_node);
}
