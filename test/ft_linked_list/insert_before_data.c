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
void init(char *initials, unsigned int size, t_node ** p_head)
{
	unsigned int i = 0;

	while (i < size)
	{
		append_to_list(p_head, initials + i);
		i++;
	}
	printf("\n");
}

void insert_before_head()
{
	t_node *head;
	t_node *node;
	int result;
	char c ;

	char	*initial= "ab";
	char	data = 'N';
	head = NULL;
	c = 'a';
	init(initial, 2, &head);
	node = insert_before_data(&head, &c, eq_char, &data);

	c = 'N';
	result = eq_char(head->data, &c);
	c = 'a';
	result = result && eq_char(head->next->data, &c);
	FT_ASSERT(result, "insert before head");
}


void insert_at_middle()
{
	t_node *head;
	t_node *node;
	int result;
	char c ;

	char	*initial= "abc";
	char data = 'N';
	head = NULL;
	init(initial, 3, &head);
	c = 'b';
	node = insert_before_data(&head, &c, eq_char, &data);

	c = 'N';
	result = eq_char(node->data, &c);
	c = 'b';
	result = result && eq_char(node->next->data, &c);
	FT_ASSERT(result, "insert before a node at the middle");
}
void insert_at_end()
{
	t_node *head;
	t_node *node;
	int result;
	char c ;

	char	*initial= "abc";
	char data = 'N';
	head = NULL;
	init(initial, 3, &head);
	c = 'c';
	node = insert_before_data(&head, &c, eq_char, &data);

	c = 'N';
	result = eq_char(node->data, &c);
	c = 'c';
	result = result && eq_char(node->next->data, &c);
	FT_ASSERT(result, "insert before a node at the end");
}
int main()
{
	insert_before_head();
	insert_at_middle();
	insert_at_end();
}
