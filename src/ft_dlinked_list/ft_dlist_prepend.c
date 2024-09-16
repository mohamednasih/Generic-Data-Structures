#include "ft_dlinked_list.h"

t_dnode	*ft_dlist_prepend(t_dlist *list, void *data)
{
	t_dnode	*new_node;

	new_node = (t_dnode *)malloc(sizeof(t_dnode));
	if ( new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->next = list->head;
	new_node->prev = NULL;
	if (list->head != NULL)
		list->head->prev = new_node;
	list->head = new_node;
	return (new_node);
}
