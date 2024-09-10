#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"

int eq_char(void *v1, void *v2)
{
	char *c1 = v1;
	char *c2 = v2;
	return (*c1 == *c2);
}

void print_char(void *d)
{
	char *c;

	c = d;
	printf("%c ---> ", *c);
}

int main()
{
	t_node	*head;
	t_node	*node;
	char	s[15] = "abcd";
	char 	data[] ="ABD";
	int result;
	int i;
	char c;

	head = NULL;
	result = insert_after_data(head, &data[0], eq_char, data) == NULL;
	FT_ASSERT(result, "list is empty");
	i = 0;
	
	while (i < 4)	
	{
		append_to_list(&head, s + (i++));
	}
	printf("list for testing \n");
	foreach_list(head, print_char);	
	printf("\n");
	
	c = 'a';
	node = insert_after_data(head, &c, eq_char, &data[0]);	
	c = 'A'; 
	result = head->next == node && eq_char(node->data, &c);
	c = 'b';
	result = result && eq_char(node->next->data, &c);
	FT_ASSERT(result , "insert after data in head");

	
	c = 'b';
	node = insert_after_data(head, &c, eq_char, &data[1]);	
	c = 'B'; 
	result = eq_char(node->data, &c);
	c = 'b';
	result = result && ft_find_node(head, &c, eq_char)->next == node;
	c = 'c';
	result = result && eq_char(node->next->data, &c);
	FT_ASSERT(result , "insert after data in middle");

	c = 'd';
	node = insert_after_data(head, &c, eq_char, &data[2]);	
	c = 'D'; 
	result = eq_char(node->data, &c);
	c = 'd';
	result = result && ft_find_node(head, &c, eq_char)->next == node;
	c = 'c';
	result = result && node->next == NULL;
	FT_ASSERT(result , "insert after data in the tail");

	foreach_list(head, print_char);	
}
