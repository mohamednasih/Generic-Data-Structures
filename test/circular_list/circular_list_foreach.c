#include "circular_list.h"
#include "test.h"
#include "ft_types.h"
#include "ft_string.h"

char buffer[2];
int	i = 0;
void fill_buffer(const t_cnode *node)
{
	ft_memcpy(buffer + i, node->data, 1);
	i++;
	printf("%c ==> ", *((char *)node->data));
}

t_cnode *create_node(char c)
{
	t_cnode	*node = malloc(sizeof(t_cnode));
	char *data = malloc(1);
	node->data = data;

	ft_memcpy(data, &c, 1);
	return node;
}
void add_next(t_cnode *node1, t_cnode *itsnext)
{
	node1->next = itsnext;
}
void destroy(t_cnode * node)
{
	free(node);
}
int main()
{
	t_circular_list list;
	t_cnode *head;
	t_cnode *node;
	int	result;

	head = create_node('a');
	list.head = head;
	node = create_node('b');
	add_next(head, node);
	add_next(node, head);
	circular_list_foreach(list, fill_buffer);
	result = ft_memcmp(buffer, "ab", 2);
	FT_ASSERT(result, "circular list copied to a buffer.");
}
