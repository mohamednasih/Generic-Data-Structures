#include "circular_list.h"
#include "test.h"

void free_node(t_cnode *node)
{
	free(node);
	printf("freeing a node -");
}

t_cnode *create_node()
{
	return malloc(sizeof(t_cnode));
}

void test_freeing_single_node()
{

	t_circular_list	list;
	int result;
	
	list.free_node = free_node;
	t_cnode *a = create_node();
	a->next = a;
	list.head = a;
	
	circular_list_free(&list);
	result = list.head == NULL;
	FT_ASSERT(result, "freeing a single-node circular list.");
}

void	test_freeing_mul_nodes()
{
	t_circular_list	list;
	int result;
	
	list.free_node = free_node;
	t_cnode *a = create_node();
	t_cnode *b = create_node();
	t_cnode *c = create_node();
	a->next = b;
	b->next = c;
	c->next = a;
	list.head = a;
	
	circular_list_free(&list);
	result = list.head == NULL;
	FT_ASSERT(result, "freeing a multi nodes circular list.");
}
int main()
{
	t_circular_list	list;
	
	list.free_node = free_node;
	circular_list_free(&list);
	FT_ASSERT(1,"no problem in freeing empty list.");
	test_freeing_single_node();
	test_freeing_mul_nodes();
}
