#include "ft_types.h"
#include "test.h"
#include "ft_string.h"

int	main(void)
{
	int arr1[4] = {1,2,3,4};
	int arr2[4] = {1,2,3,4};
	FT_ASSERT(ft_memcmp(arr1, arr2, sizeof(arr1)), "EQUAL ARRAY OF INTEGERS");

	arr1[1] = 789;
	FT_ASSERT(!ft_memcmp(arr1, arr2, sizeof(arr1)), "UNEQUAL ARRAY OF INTEGERS");

	char c = 9;
	char *pc = &c;
	
	FT_ASSERT(ft_memcmp(pc, &c, sizeof(char *)), "BUFFER OF POINTERS TO CHAR");

	char d = 9;
	char *pd = &d;
	FT_ASSERT(!ft_memcmp(pc, pd, sizeof(char *)), "DIFFERENT BUFFERS TO CHAR *");
}
