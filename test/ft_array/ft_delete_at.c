#include "ft_types.h"
#include "test.h"
#include "ft_array.h"
#include "ft_string.h"

typedef	struct 
{
	void	*arr;
	t_size size;
	t_index index;
	void *expected;
	t_size el_size;

}t_test;

int verify(t_test t)
{
	ft_delete_at(t.arr, t.size, t.index, t.el_size);
	return (ft_memcmp(t.arr, t.expected, t.el_size * t.size));
}
int main(void)
{

	int result;

	t_test test_1 = {(int []){1,2,3,4,5}, 5, 0, (int []){2,3,4,5,5}, sizeof(int)};
	result = verify(test_1);
	FT_ASSERT(result == 1, "delete at index 0");


	t_test test_2 = {(char []){1,2,3,5,5}, 5, 3, (char []){1,2,3,5,5}, sizeof(char)};
	result = verify(test_2);
	FT_ASSERT(result == 1, "delete from middle");

	
	t_test test_3 = {(char []){1,2,3}, 3, 2, (char []){1,2,3}, sizeof(char)};
	result = verify(test_3);
	FT_ASSERT(result == 1, "delete from the end");
}
