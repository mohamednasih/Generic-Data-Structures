#include "ft_dlinked_list.h"
#include "ft_types.h"
#include "ft_string.h"
#include "test.h"
void print_char(t_dnode *v)
{
	char *c = v->data;
	printf("%c <===> ",*c);
}
void	test_append_to_empty(t_dnode *node)
{
	int result ;
	char expected_data;

	expected_data = 'a';
	result = node->next == NULL;
	result = result && node->prev == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	FT_ASSERT(result, "append to an empty dlist");
}

void	test_append_to_single_node(t_dnode *node)
{
	int result ;
	char expected_data;
	char expected_prevdata;

	expected_data = 'b';
	expected_prevdata = 'a';
	result = node->next == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	result = result && ft_memcmp(node->prev->data, &expected_prevdata, 1);
	FT_ASSERT(result, "append to a single-node list");
}

void	test_append_multi_el(t_dnode *node)
{
	int result ;
	char expected_data;
	char expected_prevdata;

	expected_data = 'c';
	expected_prevdata = 'b';
	result = node->next == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	result = result && ft_memcmp(node->prev->data, &expected_prevdata, 1);
	FT_ASSERT(result, "append to a  list with multiple elments");
}

int main()
{
	t_dlist dlist;
	t_dnode	*new_node;

	char *data = "abcdefgh";
	new_node = ft_dlist_append(&dlist, data++);
	test_append_to_empty(new_node);
	new_node = ft_dlist_append(&dlist, data++);
	test_append_to_single_node(new_node);
	new_node = ft_dlist_append(&dlist, data++);
	test_append_multi_el(new_node);
}
