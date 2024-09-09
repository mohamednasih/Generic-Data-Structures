#include "test.h"
#include "ft_linked_list.h"
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
int main()
{
	t_node *head;
	int m[] = {1,2,3};
	int result;
	int i = 0;

	head = NULL;
	append_to_list(&head, m + (i++));
	result = is_eq(head->data, 1);
	FT_ASSERT(head->next == NULL && result, "initialazing a list");

	append_to_list(&head, m + (i++));
	result = is_eq(head->next->data,2);
	FT_ASSERT(result && head->next->next == NULL, "adding a 2nd element to a list");

	append_to_list(&head, m + (i++));
	result = is_eq(head->next->next->data,3);
	FT_ASSERT(result && head->next->next->next == NULL, "adding a 3rd element to a list");
}
