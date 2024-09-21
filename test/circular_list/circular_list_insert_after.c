#include "circular_list.h"
#include "ft_types.h"
#include "test.h"
#include "ft_string.h"

int match(const t_cnode *node, const void *target)
{
	return ft_memcmp(node->data, target, 1);
}

void free_node(t_cnode * node)
{
	free(node);
}

void test_empty_list()
{
	t_circular_list	list;
	int result;
	list.head = NULL;
	list.free_node = free_node;

	circular_list_insert_after(&list, "a", "i", match);
	result = list.head != NULL;
	FT_ASSERT(result, "insert after: empty list");
}

void pr(const t_cnode *node)
{
	printf("%c ==> ", *((char *)node->data));
}

void test_there_is_match()
{
	t_circular_list	list;
	t_cnode *node;
	t_cnode *new_node;
	int result;
	char *data = "abcd";
	list.head = NULL;
	list.free_node = free_node;

	result = 0;
	while (result++ < 3)
		circular_list_prepend(&list, data++);
	new_node = circular_list_insert_after(&list, "a", data++, match);
	node = circular_list_find(list, "a", match);
	result = ft_memcmp(new_node->next, list.head, sizeof(t_cnode *));
	result = result && ft_memcmp(node->next->data, "d", 1);
	FT_ASSERT(result,"insert after match.");
	circular_list_free(&list);
}

void test_there_is_no_match()
{
	t_circular_list	list;
	t_cnode *node;
	t_cnode *new_node;
	int result;
	char *data = "abcd";
	list.head = NULL;
	list.free_node = free_node;

	result = 0;
	while (result++ < 3)
		circular_list_prepend(&list, data++);
	new_node = circular_list_insert_after(&list, "z", data++, match);
	node = circular_list_find(list, "a", match);
	result = ft_memcmp(new_node->next, list.head, sizeof(t_cnode *));
	result = result && ft_memcmp(node->next->data, "d", 1);
	FT_ASSERT(result,"insert when there is no match.");
	circular_list_free(&list);
}
int main()
{
	test_empty_list();
	test_there_is_match();
	test_there_is_no_match();
}
