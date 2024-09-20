#include "circular_list.h"

t_cnode	*circular_list_append(t_circular_list *list, void *data)
{
	t_cnode	*head;
	t_cnode	*current;
	t_cnode	*new_node;

	new_node = (t_cnode *)malloc(sizeof(t_cnode *));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
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
