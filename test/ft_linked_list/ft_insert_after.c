#include "test.h"
#include "ft_linked_list.h"
void print_int(void *data)
{
	int *m = data;
	printf("%d ->",*m); 
}
int is_eq(t_node *node, int value)
{
	if (node == NULL)
		return (0);
	int *m = node->data;
	return (*m == value);
}
int main()
{
	t_node *head;
	int m[] = {1,2,3,4};
	int i = 0;
	int result;

	head = NULL;
	ft_prepend(&head, m + (i++));
	result = is_eq(head, 1);

	printf("\ninitial list \n");
	foreach_list(head, print_int);
	FT_ASSERT(result, "\ninitialazing a list");

	printf("\ninsert after 1 \n");
	ft_insert_after(head, m + (i++));
	foreach_list(head, print_int);
	result = is_eq(head->next, 2);
	FT_ASSERT(result, "\ninsert a node after head at the end");
	FT_ASSERT(head->next->next == NULL, "new inserted node doesnt have a next node");

	printf("\ninsert after head \n");
	ft_insert_after(head, m + (i++));
	foreach_list(head, print_int);
	result = is_eq(head->next, 3);
	FT_ASSERT(result, "\ninsert at the middle ");
	result = is_eq(head->next->next, 2);
	FT_ASSERT(result, "the next node of the newly inserted node is correct");
}
