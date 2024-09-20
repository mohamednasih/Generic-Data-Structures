#include "circular_list.h"
#include "ft_types.h"
#include "test.h"
#include "ft_string.h"

void free_node(t_cnode * node)
{
	free(node);
}

int	eq(const t_cnode *node, const void *c)
{
	return ft_memcmp(node->data, c, 1);
}
void	test_empty_list()
{
	t_circular_list	list;
	t_cnode	*node;
	list.head = NULL;
	int	result;

	list.free_node = free_node;
	node = circular_list_find(list,"a", eq);
	result = node == NULL;
	FT_ASSERT(result, "search in an empty list.");
	circular_list_free(&list);
}

void	test_matches()
{
	t_circular_list	list;
	t_cnode	*node;
	list.head = NULL;
	int	result;
	char *data = "abc";

	list.free_node = free_node;
	circular_list_append(&list, data); 
	circular_list_append(&list, data + 1); 
	circular_list_append(&list, data + 2); 
	node = circular_list_find(list,"a", eq);
	result = node != NULL;
	FT_ASSERT(result, "found a node that match a criteria.");
	node = circular_list_find(list,"h", eq);
	result = node == NULL;
	FT_ASSERT(result, "no node match the criteria.");
	circular_list_free(&list);
}
int main ()
{
	test_empty_list();
	test_matches();
}
