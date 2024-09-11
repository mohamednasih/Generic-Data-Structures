#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"


int eq_char(void *v1, void *v2)
{
	const char	*c1;
	const char	*c2;

	c1 = v1;
	c2 = v2;

	return *c1 == *c2;
}

void print_char(void *c)
{
	printf("%c ->", *(char *)c);
}
int main()
{
	t_node *head;
	char *str;
	int	result;
	char	c;

	str = "abc";
	head = array_to_linked_list(str, 3, sizeof(char));	
	c = 'a';
	result = eq_char(head->data, &c); 
	c = 'b';
	result = result && eq_char(head->next->data, &c); 
	c = 'c';
	result = result && eq_char(head->next->next->data, &c); 
	result = result && head->next->next->next == NULL; 
	free_list(head);
	FT_ASSERT(result, "str abc inserted");
}
