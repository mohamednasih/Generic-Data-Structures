#include "circular_list.h"
#include "ft_types.h"
#include "ft_string.h"
#include "test.h"

void *get_c(char c)
{
	void *cm = malloc(1);
	ft_memcpy(cm, &c, 1);
	return (cm);
}

void callback(const t_cnode * node)
{
	printf("%c ==>",*((char *)node->data));
}

void free_node(t_cnode *node)
{
	free(node->data);
	free(node);
}

t_cnode *new_cnode(void *data)
{
	t_cnode *node = (t_cnode *)malloc(sizeof(t_cnode));
	node->data = data;
	return node;
}

void test_prepending_to_empty_list()
{
	t_circular_list	list;
	int	result;

	circular_list_prepend_node(&list,new_cnode(get_c('a')));
	result = ft_memcmp(list.head->data, "a", 1);
	result = result && ft_memcmp(list.head->next,list.head, sizeof(t_cnode *));
	FT_ASSERT(result, "prepend to an empty list.");
	list.free_node = free_node;
	circular_list_free(&list);
}
void test_prepending_not_empty()
{
	t_circular_list	list;
	t_cnode *tail;
	int	result;
	list.head = NULL;

	circular_list_prepend_node(&list,new_cnode(get_c('a')));
	circular_list_prepend_node(&list,new_cnode(get_c('b')));
	circular_list_prepend_node(&list,new_cnode(get_c('c')));
	tail = list.head->next->next;
	result = tail || 1;
	result = ft_memcmp(list.head->data, "c", 1);
	result = result && ft_memcmp(tail->next, list.head, sizeof(t_cnode *));
	result = result && ft_memcmp(tail->data, "a", 1);
	FT_ASSERT(result, "prepend more than one node.");
	list.free_node = free_node;
	circular_list_free(&list);
}
int main()
{
	test_prepending_to_empty_list();
	test_prepending_not_empty();
}


