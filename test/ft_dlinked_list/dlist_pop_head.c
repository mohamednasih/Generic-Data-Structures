#include "ft_dlinked_list.h"
#include "test.h"
#include "ft_types.h"
#include "ft_string.h"

void destroy(t_dnode *node)
{
	free(node);
}
void remove_head_of_multi_el(t_dlist list)
{
	int result ;

	result = ft_memcmp(list.head->data, "2",1);
	result = result && list.head->prev == NULL;
	FT_ASSERT(result, "remove head of 1<=>2<=>3");
}

void remove_head_of_two_nodes(t_dlist list)
{
	int result ;

	result = ft_memcmp(list.head->data, "3",1);
	result = result && list.head->prev == NULL;
	FT_ASSERT(result, "remove head of 2<=>3");
}
void remove_head_of_single_node(t_dlist list)
{
	int result ;

	result = list.head == NULL;
	FT_ASSERT(result, "remove head of 3");
}
int main()
{
	t_dlist	dlist;
	char *data = "123";
	dlist.destroy = destroy;
	while (*data)
		ft_dlist_append(&dlist, data++);
	dlist_pop_head(&dlist);
	remove_head_of_multi_el(dlist);
	dlist_pop_head(&dlist);
	remove_head_of_two_nodes(dlist);
	dlist_pop_head(&dlist);
	remove_head_of_single_node(dlist);
	dlist_pop_head(&dlist);
	dlist_pop_head(&dlist);
	FT_ASSERT(1, "trying to pop head of an empty dlist");
}
