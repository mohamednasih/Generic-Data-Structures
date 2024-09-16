#include "ft_types.h"
#include "ft_string.h"
#include "ft_dlinked_list.h"
#include "test.h"

int data_eq(void *data, void *target)
{
	return ft_memcmp(data, target, 1);
}
void	search_empty_list(t_dnode * node)
{
	FT_ASSERT(node == NULL, "search in an empty list");
}

void	test_target_at_head(t_dnode *node)
{
	int result;

	result = ft_memcmp(node->data, "c", 1);
	FT_ASSERT(result, "target at the head of the list");
}


void	test_target_at_middle(t_dnode *node)
{
	int result;

	result = ft_memcmp(node->data, "b", 1);
	FT_ASSERT(result, "target at the middle of the list");
}

void	test_target_at_tail(t_dnode *node)
{
	int result;

	result = ft_memcmp(node->data, "a", 1);
	FT_ASSERT(result, "target at the tail of the list");
}
void	print_char(t_dnode *n)
{
	char *data = n->data;
	printf("%c <===>", *data);
}

void	test_target_not_part(t_dnode * node)
{
	FT_ASSERT(node == NULL, "target not part of the list");
}

int main()
{
	t_dlist list;
	t_dnode *node;
	list.head = NULL;
	char target;
	char *data = "abc";

	target = 'a';
	node = ft_dlist_find(list, &target, data_eq);
	search_empty_list(node);
	while (*data)
		ft_dlist_prepend(&list, data++);
	target = 'c';
	node = ft_dlist_find(list, &target, data_eq);
	test_target_at_head(node);


	target = 'b';
	node = ft_dlist_find(list, &target, data_eq);
	test_target_at_middle(node);

	target = 'a';
	node = ft_dlist_find(list, &target, data_eq);
	test_target_at_tail(node);

	target = 'x';
	node = ft_dlist_find(list, &target, data_eq);
	test_target_not_part(node);
}
