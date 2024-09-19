#include "circular_list.h"

void	circular_list_free(t_circular_list *list)
{
	t_cnode	*head;
	t_cnode	*current;
	t_cnode	*tmp;

	head = list->head;
	if (head == NULL)
		return ;
	current = head->next;
	while (current != head)
	{
		tmp = current;
		current = current->next;
		list->free_node(tmp);
	}
	list->free_node(head);
	list->head = NULL;
}



