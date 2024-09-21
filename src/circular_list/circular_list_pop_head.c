#include "circular_list.h"

t_cnode *circular_list_pop_head(t_circular_list *list)
{
	t_cnode	*head;
	t_cnode	*current;
	
	head = list->head;
	if (head == NULL)
		return (NULL);
	if (head == head->next)
	{
		list->head = NULL;
		return (head);
	}
	current = head->next;
	while (current->next != head)
		current = current->next;
	current->next = head->next;
	list->head = head->next;
	return (head);
}
