#include <stdlib.h>
#include "ft_linked_list.h"
#include "test.h"
#include  "ft_string.h"

int	is_not_lower(void * vp)
{
	char	*c = vp;
	return !(*c  >= 'a' && *c <= 'z');	
}
void print_c(void *v)
{
	printf("%c -->",*((char *)v));
}
void foreach(t_node *head)
{
	foreach_list(head, print_c);
	printf("\n");
}
void	remove_nothing()
{
	t_node	*head;
	t_node	*deleted;
	int	result;

	head = array_to_linked_list("abc", 3, sizeof(char));
	deleted = remove_if(&head, is_not_lower);
	result = deleted == NULL;	
	FT_ASSERT(result, "nothing deleted because as nothing match the criteria");
}

void	remove_everything()
{
	t_node	*head;
	t_node	*deleted;
	int	result;

	head = array_to_linked_list("AB", 2, sizeof(char));
	deleted = remove_if(&head, is_not_lower);
	result = head == NULL;	
	result = result && (deleted->next->next == NULL);
	FT_ASSERT(result, "all items were deleted bc they matched the criteria");
}


void	remove_some_nodes()
{
	t_node	*head;
	t_node	*deleted;
	int	result;
	char	c;

	head = array_to_linked_list("ABabOP", 6, sizeof(char));
	deleted = remove_if(&head, is_not_lower);
	c = 'a';
	result = ft_memcmp(head->data, &c, 1);	
	c = 'b';
	result = result && ft_memcmp(head->next->data, &c, 1);	
	result = result && head->next->next == NULL;
	result = result && deleted->next->next->next->next == NULL;
	FT_ASSERT(result, "Only matching items were deleted; non-matching items remain");
}
int main()
{
	remove_nothing();
	remove_everything();
	remove_some_nodes();
}
