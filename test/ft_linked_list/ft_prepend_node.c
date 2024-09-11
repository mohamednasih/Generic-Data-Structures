#include "test.h"
#include "ft_linked_list.h"
#include <stdlib.h>
void print_int(void *data)
{
	int *m = data;
	printf("%d ->",*m); 
}
int is_eq(void *data, int value)
{
	int *m = data;
	return *m == value;
}
t_node *create_node(void *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	return (node);
}
int main()
{
	t_node	*head;
	t_node	*new_node;
	int m[] = {1,2,3};
	int result;

	head = NULL;
	new_node = create_node(&m[0]);
	ft_prepend_node(&head, new_node);
	result = is_eq(head->data, 1);
	FT_ASSERT(head->next == NULL && result, "initialazing a list");

	new_node = create_node(&m[1]);
	ft_prepend_node(&head, new_node);
	result = is_eq(head->data,2);
	FT_ASSERT(result && head->next->next == NULL, "adding a 2nd element to a list");

	new_node = create_node(&m[2]);
	ft_prepend_node(&head, new_node);
	result = is_eq(head->data,3);
	FT_ASSERT(result && head->next->next->next == NULL, "adding a 3rd element to a list");
}
