#include "ft_types.h"
#include "ft_string.h"

void	ft_insert_at(void *array, void *elem, t_index i, t_size  elem_size, t_index upper_bound) 
{
	void	*dest;
	void	*src;
	t_index	j;

	j = upper_bound;
	while (j > i)
	{
		dest = array + j * elem_size;
		src = array + (j - 1) * elem_size;
		ft_memcpy(dest, src, elem_size);
		j--;
	}
	dest = array + j * elem_size;
	ft_memcpy(dest, elem, elem_size);
}
