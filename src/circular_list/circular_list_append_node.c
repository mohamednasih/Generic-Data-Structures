#include "circular_list.h"

t_cnode	*circular_list_append_node(t_circular_list *list,t_cnode *new_node)
{
	t_cnode	*head;
	t_cnode	*current;

	if (new_node == NULL)
		return (NULL);
	head = list->head;
	if (head == NULL)
	{
		new_node->next = new_node;
		list->head = new_node;
		return new_node;
	}
	current = head;
	new_node->next = head;
	while (current->next != head)
		current = current->next;
	current->next = new_node;
	return (new_node);
}
