#include "circular_list.h"

t_cnode *circular_list_find(t_circular_list list, const void *target, int match(const t_cnode *, const void *))
{
	t_cnode	*head;
	t_cnode *current;

	head = list.head;
	if (head == NULL) return NULL;
	current = head;
	while (current->next != head && !match(current, target))
		current = current->next;
	if (match(current, target)) return (current);
	return (NULL);
}
