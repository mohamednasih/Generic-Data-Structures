#include "circular_list.h"
#include "test.h"

int	circular_list_remove_if(t_circular_list *list, t_circular_list *removed_nodes, int match(t_cnode *))
{
	t_cnode	*head;
	t_cnode *current;
	t_cnode *tmp;
	int count;

	count = 0;
	head = list->head;
	while (match(list->head))
	{
		if (head == list->head->next)
		{
			tmp = list->head;
			list->head = NULL;
			circular_list_append_node(removed_nodes, tmp);
			count++;
			return (count);
		}
		tmp = list->head;
		list->head= list->head->next;
		circular_list_append_node(removed_nodes, tmp);
		count++;
	}
	current = list->head;
	while (current->next != head)
	{
		if (match(current->next))
		{
			tmp = current->next;
			current->next = current->next->next;
			circular_list_append_node(removed_nodes, tmp);
			count++;
		}
		else
			current = current->next;
	}
	current->next = list->head;
	return (count);	
}
