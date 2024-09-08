#include "ft_types.h"
#include "ft_string.h"

void	ft_delete_at(void *array, t_size size, t_index index, t_size el_size)
{
	unsigned char	*dest;
	const unsigned char	*src;
	while ((index  + 1)< size)
	{
		dest = (unsigned char *)array + index * el_size;
		src = (unsigned char *)array + (index + 1) * el_size;
		ft_memcpy(dest, src, el_size);
		index++;
	}
}
