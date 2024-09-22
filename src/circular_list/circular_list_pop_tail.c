#include "circular_list.h"

t_cnode *circular_list_pop_tail(t_circular_list *list)
{
	t_cnode	*head;
	t_cnode	*current;
	t_cnode	*tail;
	
	head = list->head;
	if (head == NULL)
		return (NULL);
	if (head->next == head)
	{
		list->head = NULL;
		return (head);
	}
	current = head->next;
	while (current->next->next != head)
		current = current->next;
	tail = current->next;
	current->next = head;
	return (tail);
}
