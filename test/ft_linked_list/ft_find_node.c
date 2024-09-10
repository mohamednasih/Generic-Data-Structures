#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"

void print_int(void *data)
{
	int *value = (int *) data;
	printf("%d ->", *value);
}

int eq_int(void *data,void *data1)
{
	int *value = (int *) data;
	int *value1 = (int *) data1;
	return (value == value1);
}

int main()
{
	int numbers[] = {1,2,3,4,5,6,7,8,9,10};
	int i ;
	t_node *head;
	int result;

	head = NULL;
	i = 0;
	result = ft_find_node(head, numbers, eq_int) == NULL;
	FT_ASSERT(result, "searching on an empy list");
	while ( i < 4)
	{
		append_to_list(&head, numbers + (i++));
	}
	printf("the linked list i gonna use for testing\n");
	foreach_list(head, print_int); 
	printf("\n");

	result = eq_int(ft_find_node(head, numbers, eq_int)->data, numbers);
	FT_ASSERT(result, "searched item is at the head of th list");

	result = eq_int(ft_find_node(head, numbers + 2, eq_int)->data, numbers + 2);
	FT_ASSERT(result, "searched item is at the middle of the list");

	result = eq_int(ft_find_node(head, numbers + 3, eq_int)->data, numbers + 3);
	FT_ASSERT(result, "searched item is at the end of th list");

	result = ft_find_node(head, numbers + 7, eq_int) == NULL;
	FT_ASSERT(result, "searched item doesnt exist on the list");
}
