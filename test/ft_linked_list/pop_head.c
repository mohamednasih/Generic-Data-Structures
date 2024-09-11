#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"

int main()
{
	char *str;
	t_node	*head;
	t_node  *node;
	int result;

	
	head = NULL;
	node = pop_head(&head);
	result = node == NULL;
	FT_ASSERT(result, "trying to remove head of a an empty list");


	head = array_to_linked_list("a", 1, 1);
	result = head != NULL;
	node = pop_head(&head);
	free(node);
	result = result && (head == NULL);
	FT_ASSERT(result, "remove head of single-node list");

	str = "abc";
	head = array_to_linked_list(str, 3, 1);
	node = pop_head(&head);
	
	result = *((char *) node->data) == 'a';
	result = result && (*((char *) head->data) == 'b');
	free(node);
	free_nodes(head);
	FT_ASSERT(result, "delete head of a->b->c");
}
