#include "ft_dlinked_list.h"
#include "test.h"
#include "ft_types.h"
#include "ft_string.h"

void	destroy(t_dnode *node)
{
	free(node);
}
int is_a(void *v)
{
	return ft_memcmp(v, "a", 1);
}

int is_eq(void *v1, void *v2)
{
	return ft_memcmp(v1, v2, 1);
}
void print_char(t_dnode *d)
{
	printf("%c<==>", *((char *)d->data)); 	
}

void all_a_deleted(t_dlist list)
{
	t_dnode	*node;
	int result;

	node = ft_dlist_find(list, "a", is_eq);
	result = node == NULL;
	FT_ASSERT(result, "all a in aabaacaaa dlist were deleted");
	result = list.head->prev == NULL;
	FT_ASSERT(result, "the new head has no previous");
	node = ft_dlist_find(list, "c", is_eq);
	result = node->next == NULL;
	FT_ASSERT(result, "the new tail has no next");
}
void	test_deleting_all_nodes(t_dlist list)
{
	int result;

	result = list.head == NULL;
	FT_ASSERT(result, "all nodes were deleted");

}
int main()
{
	t_dlist	list;
	t_dlist list2;
	char *data;

	data = "aabaacaa";
	list.destroy = destroy;
	list2.destroy = destroy;
	while (*data)
	{
		ft_dlist_append(&list, data++);
	}
	dlink_remove_if(&list, is_a);
	all_a_deleted(list);

	data = "aaaaaaaaa";
	while (*data)
		ft_dlist_append(&list2, data++);
	dlink_remove_if(&list2, is_a);
	test_deleting_all_nodes(list2);
	dlink_remove_if(&list2, is_a);
	FT_ASSERT(1, "trying to delete from an empty dlist");
}
