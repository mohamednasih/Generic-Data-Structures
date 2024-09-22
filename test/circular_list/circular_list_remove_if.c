#include "circular_list.h"
#include "ft_types.h"
#include "ft_string.h"
#include "test.h"

void free_node(t_cnode * node)
{
	free(node);
}
int is_number(t_cnode *node)
{
	char *c = node->data;
	return '1' <= *c && *c <= '9';
}
void print_c(const t_cnode *node)
{
        char *c = node->data;
        printf("%c(%p) =>", *c,node);
}

void all_nodes()
{

	t_circular_list	list;
	t_circular_list numbers;
	char *data = "12345";
	int result;

	list.head = NULL;
	numbers.head = NULL;
	list.free_node = free_node;
	numbers.free_node = free_node;
	while (*data)
		circular_list_append(&list, data++);

	result = circular_list_remove_if(&list, &numbers, is_number);
	result = result == 5;
	result = result && list.head == NULL; 
	FT_ASSERT(result,"all nodes were removed");
	circular_list_free(&list);
	circular_list_free(&numbers);
}

void no_nodes()
{

	t_circular_list	list;
	t_circular_list numbers;
	char *data = "abcdef";
	int result;

	list.head = NULL;
	numbers.head = NULL;
	list.free_node = free_node;
	numbers.free_node = free_node;
	while (*data)
		circular_list_append(&list, data++);

	result = circular_list_remove_if(&list, &numbers, is_number);
	result = result == 0;
	result = result && ft_memcmp(list.head->data, "a", 1); 
	result = result && numbers.head == NULL; 
	FT_ASSERT(result,"no nodes were removed");
	circular_list_free(&list);
	circular_list_free(&numbers);
}
void	removing_multiple_nodes()
{
	t_circular_list	list;
	t_circular_list numbers;
	char *data = "12abc3de45iaaaaa";
	int result;

	list.head = NULL;
	numbers.head = NULL;
	list.free_node = free_node;
	numbers.free_node = free_node;
	while (*data)
		circular_list_append(&list, data++);

	result = circular_list_remove_if(&list, &numbers, is_number);
	result = result == 5;
	result = result && ft_memcmp(list.head->data, "a", 1); 
	FT_ASSERT(result,"all nodes that match were removed");
	circular_list_free(&list);
	circular_list_free(&numbers);
}
int main()
{
	removing_multiple_nodes();
	all_nodes();
	no_nodes();
}



