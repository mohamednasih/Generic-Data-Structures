#include "circular_list.h"
#include "ft_types.h"
#include "test.h"
#include "ft_string.h"

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

void free_node(t_cnode * node)
{
	free(node->data);
	free(node);
}
t_cnode *allocate_node(void *data)
{
	t_cnode *node = (t_cnode *)malloc(sizeof(t_cnode));
	node->data = data;
	return (node);
}
void test_appending_to_empty_list()
{
	t_circular_list	list;
	int	result;

	circular_list_append_node(&list,allocate_node(get_c('a'))); 
	result = ft_memcmp(list.head->data, "a", 1);
	result = result && ft_memcmp(list.head->next,list.head, sizeof(t_cnode *));
	FT_ASSERT(result, "append to an empty list.");
	list.free_node = free_node;
	circular_list_free(&list);
}
void test_appending_not_empty()
{
	t_circular_list	list;
	t_cnode *tail;
	int	result;
	list.head = NULL;

	circular_list_append_node(&list,allocate_node(get_c('a'))); 
	circular_list_append_node(&list,allocate_node(get_c('b')));
	circular_list_append_node(&list,allocate_node(get_c('c'))); 
	tail = list.head->next->next->next;
	result = ft_memcmp(list.head->next->data, "b", 1);
	result = result && ft_memcmp(tail, list.head, sizeof(t_cnode *));
	FT_ASSERT(result, "append more than one node.");
	list.free_node = free_node;
	circular_list_free(&list);
}
int main()
{
	test_appending_to_empty_list();
	test_appending_not_empty();
}
