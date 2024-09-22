#include "circular_list.h"

t_cnode *circular_list_prepend_node(t_circular_list *list, t_cnode *new_node)
{
	t_cnode *head;
	t_cnode *tail;

	if (new_node == NULL)
		return (NULL);
	head = list->head;
	if (head == NULL)
	{
		list->head = new_node;
		new_node->next = new_node;
		return (new_node);
	}
	tail = head;
	while (tail->next != head)
		tail = tail->next;
	tail->next = new_node;
	new_node->next = head;
	list->head = new_node;
	return (new_node);
}
	
	
