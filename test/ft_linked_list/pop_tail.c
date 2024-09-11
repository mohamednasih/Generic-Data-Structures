#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"
void	print_char(void * v)
{
	printf("%c -->", *((char *)v));
}
void foreach(t_node *node, void (*f))
{
	foreach_list(node, f);
	printf("\n");
}

void	empty_list()
{
	t_node	*head;
	t_node *tail;
	int	result;

	head = NULL; 
	tail = pop_tail(&head);
	result = tail == NULL;
	FT_ASSERT(result, "trying to pop tail of an empty list");
}

void	single_node()
{
	t_node	*head;
	t_node *tail;
	int	result;

	head = array_to_linked_list("a", 1, sizeof(char));
	tail = pop_tail(&head);
	result = *((char *)tail->data) == 'a';
	result = result && head == NULL;
	free(tail);
	free_nodes(head);
	FT_ASSERT(result, "pop tail of single-node list");
}

void	multi_node()
{
	t_node	*head;
	t_node *tail;
	int	result;

	head = array_to_linked_list("abc", 3, sizeof(char));
	tail = pop_tail(&head);
	result = *((char *)tail->data) == 'c';
	result = result && head->next->next == NULL;
	free(tail);
	free_nodes(head);
	FT_ASSERT(result, "pop tail of multi-nodes list");
}

int main()
{
	empty_list();
	single_node();
	multi_node();
}
