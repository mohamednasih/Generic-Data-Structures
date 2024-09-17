#include "ft_dlinked_list.h"
#include "ft_types.h"
#include "ft_string.h"
#include "test.h"
void print_char(t_dnode *v)
{
	char *c = v->data;
	printf("%c <===> ",*c);
}
void	test_prepend_to_empty(t_dnode *node)
{
	int result ;
	char expected_data;

	expected_data = 'a';
	result = node->next == NULL;
	result = result && node->prev == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	FT_ASSERT(result, "prepend to an empty dlist");
}

void	test_prepend_to_single_node(t_dnode *node)
{
	int result ;
	char expected_data;
	char expected_nextdata;

	expected_data = 'b';
	expected_nextdata = 'a';
	result = node->prev == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	result = result && ft_memcmp(node->next->data, &expected_nextdata, 1);
	result = result && ft_memcmp(node->next->prev->data, &expected_data, 1);
	FT_ASSERT(result, "prepend to a single-node list");
}

void	test_prepend_multi_el(t_dnode *node)
{
	int result ;
	char expected_data;
	char expected_nextdata;

	expected_data = 'c';
	expected_nextdata = 'b';
	result = node->prev == NULL;
	result = result && ft_memcmp(node->data, &expected_data, 1);
	result = result && ft_memcmp(node->next->data, &expected_nextdata, 1);
	result = result && ft_memcmp(node->next->prev->data, &expected_data, 1);
	FT_ASSERT(result, "prepend to a  list with multiple elments");
}

void destroy(t_dnode * node)
{
        char *c = node->data;
        printf("destroying %c \n", *c);
        free(node);
}

int main()
{
	t_dlist dlist;
	t_dnode	*new_node;
	dlist.destroy = destroy;

	char *data = "abc";
	new_node = ft_dlist_prepend(&dlist, data++);
	test_prepend_to_empty(new_node);
	new_node = ft_dlist_prepend(&dlist, data++);
	test_prepend_to_single_node(new_node);
	new_node = ft_dlist_prepend(&dlist, data++);
	test_prepend_multi_el(new_node);
	free_dlist(dlist);
}
