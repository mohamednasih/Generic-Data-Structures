#include "ft_string.h"
#include "test.h"

int	main(void)
{
	int	src = 1337;
	int	dest = 0;
	printf("testing ft_memcpy \n");

	ft_memcpy(&dest, &src, sizeof(int));
	FT_ASSERT((dest == src),"Success: copying  an integer");

	int	*psrc = &src;
	int	*pdest = NULL;

	ft_memcpy(&psrc, &pdest, sizeof(int *));
	FT_ASSERT(pdest == psrc, "Sucess: copying a pointer");
}
