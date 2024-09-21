#include "circular_list.h"

t_cnode *circular_list_insert_after(t_circular_list *list, void *target,void *data, int match(const t_cnode *,const void *))
{
	t_cnode *matched;
	t_cnode	*new_node;
	
	matched = circular_list_find(*list, target, match);
	if (matched == NULL)
		return circular_list_append(list, data);	
	new_node = (t_cnode *)malloc(sizeof(t_cnode));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = matched->next;
	matched->next = new_node;
	return new_node;
}
