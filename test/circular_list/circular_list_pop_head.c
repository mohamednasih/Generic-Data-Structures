#include "circular_list.h"
#include "ft_types.h"
#include "test.h"
#include "ft_string.h"

void	free_node(t_cnode *node)
{
	free(node);
}

void	test_single_node()
{
	t_circular_list	list;
	t_cnode *node;
	int	result;
	list.head = NULL;
	list.free_node = free_node;
	char *data = "a";

	circular_list_append(&list, data);
	node = circular_list_pop_head(&list);
	result = ft_memcmp(node->data, "a", 1);
	result = result && list.head == NULL;
	FT_ASSERT(result, "pop head of a single node list");
	circular_list_free(&list);
}

void	test_multi_nodes()
{
	t_circular_list list;
	list.head = NULL;
	t_cnode *node;
	int	result;
	list.free_node = free_node;
	char *data = "ab";

	circular_list_append(&list, data++);
	circular_list_append(&list, data++);
	node = circular_list_pop_head(&list);
	result = ft_memcmp(node->data, "a", 1);
	result = result && ft_memcmp(list.head->data, "b", 1);
	result = result && ft_memcmp(list.head, list.head->next, sizeof(t_cnode *));
	FT_ASSERT(result, "pop head of a multi-nodes.");
	circular_list_free(&list);
}
int main()
{
	test_single_node();
	test_multi_nodes();
}
