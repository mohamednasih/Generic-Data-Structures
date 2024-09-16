#include "ft_dlinked_list.h"

t_dnode	*ft_dlist_append(t_dlist *list, void *data)
{
	t_dnode	*current;
	t_dnode	*new_node;

	new_node = (t_dnode *)malloc(sizeof(t_dnode));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->data = data;
	current = list->head;
	if (current == NULL)
	{
		new_node->prev = NULL;
		list->head = new_node;
		return (new_node);
	}
	while (current->next)
		current = current->next;
	new_node->prev = current;
	current->next = new_node;
	return (new_node);
}
