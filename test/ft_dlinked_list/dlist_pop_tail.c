#include "ft_dlinked_list.h"
#include "test.h"
#include "ft_types.h"
#include "ft_string.h"

void destroy(t_dnode *node)
{
	free(node);
}
void remove_tail_of_multi_el(t_dlist list)
{
	int result ;

	result = list.head->next->next == NULL;
	FT_ASSERT(result, "remove tail of 1<=>2<=>3");
}

void remove_tail_of_two_nodes(t_dlist list)
{
	int result ;

	result = list.head->next == NULL;
	FT_ASSERT(result, "remove tail of 1<=>2");
}
void remove_tail_of_single_node(t_dlist list)
{
	int result ;

	result = list.head == NULL;
	FT_ASSERT(result, "remove tail  of 1");
}
int main()
{
	t_dlist	dlist;
	char *data = "123";
	dlist.destroy = destroy;
	while (*data)
		ft_dlist_append(&dlist, data++);
	dlist_pop_tail(&dlist);
	remove_tail_of_multi_el(dlist);
	dlist_pop_tail(&dlist);
	remove_tail_of_two_nodes(dlist);
	dlist_pop_tail(&dlist);
	remove_tail_of_single_node(dlist);
	dlist_pop_tail(&dlist);
	dlist_pop_tail(&dlist);
	FT_ASSERT(1, "trying to pop tail of an empty dlist");
}
