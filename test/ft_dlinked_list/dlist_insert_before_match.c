#include "ft_dlinked_list.h"
#include "test.h"
#include "ft_types.h"
#include "ft_string.h"

int greater(void *v1, void *v2)
{
	char *c1 = v1;
	char *c2 = v2;
	if (*c1 >= *c2)
		return 1;
	return 0;
}
void destroy(t_dnode *d)
{
	free(d);
}
void print_char(t_dnode *d)
{
	char *c;
	c = d->data;
	printf("%c <===> ", *c);
}

int data_eq(void *v1, void *v2)
{
	return ft_memcmp(v1, v2,1);
}
void test_a_is_at_head(t_dnode *node)
{
	int result;
	
	result = data_eq(node->data,"a");
	FT_ASSERT(result, "a is a the head");
}

void	test_b_is_bet_a_c(t_dnode *node)
{
	int result;

	result = data_eq(node->next->data, "c");
	result = result && data_eq(node->prev->data, "a");
        FT_ASSERT(result, "b is between a and c");
}


void	test_z_is_at_tail(t_dnode *node)
{
	int result;

	result = node->next == NULL;
	result = result && data_eq(node->prev->data, "g");
        FT_ASSERT(result, "z is at the tail and after g");

}
int main()
{
	char *data ="zdcbaefgaa";
	t_dlist list;
	t_dnode	*node;

	list.destroy = destroy;
	while (*data)
	{
		dlist_insert_before_match(&list, greater, data++);
	}
	test_a_is_at_head(list.head);

	node = ft_dlist_find(list, "b", data_eq);
	test_b_is_bet_a_c(node);

	node = ft_dlist_find(list, "z", data_eq);
	test_z_is_at_tail(node);

	foreach_dlist(list, print_char);
	printf("\n");
	free_dlist(list);
}
