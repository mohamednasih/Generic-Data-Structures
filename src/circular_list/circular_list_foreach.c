#include "circular_list.h"

void	circular_list_foreach(const t_circular_list list, void callback(const t_cnode * node))
{
	const t_cnode	*head;
	const t_cnode	*current;
	
	head = list.head;
	if (head == NULL) return ;
	callback(head);
	current = head->next;
	while (current != head)
	{
		callback(current);
		current = current->next;
	}
}
