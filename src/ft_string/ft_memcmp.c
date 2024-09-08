#include "ft_types.h"

int	ft_memcmp(const	void *buffer1, const void *buffer2, t_size buffer_size)
{
	const	unsigned char *s1;
	const	unsigned char *s2;
	
	while(buffer_size--)
	{
		s1 = (const unsigned char *) buffer1 + buffer_size;		
		s2 = (const unsigned char *) buffer2 + buffer_size;
		if (*s1 != *s2)
			return (0);
	}
	return (1);
}
