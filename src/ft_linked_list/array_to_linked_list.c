#include <stdlib.h>
#include "ft_linked_list.h"
#include "ft_types.h"
#include <stdio.h>
#include "ft_string.h"


t_node	*array_to_linked_list(void *buffer, t_size size, t_size el_size)
{
	t_node	*head;
	char	*pointer;
	unsigned int	i;
	void	*new_data;

	head = NULL;
	pointer = (char *) buffer;
	i = 0;
	while (i < size)
	{
		new_data = malloc(sizeof(el_size));
		ft_memcpy(new_data, pointer, el_size);
		append_to_list(&head, new_data);
		pointer += el_size;
		i++;
	}
	return (head);
}
