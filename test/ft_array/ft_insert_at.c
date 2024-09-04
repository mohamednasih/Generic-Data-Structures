#include "ft_types.h"
#include "ft_array.h"
#include "ft_string.h"
#include "test.h"

int array_eq(int arr1[] , int arr2[], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr1[i] != arr2[i])
			return 0;
		i++;
	}
	return 1;
}
int main(void)
{
	int arr[5] = {0};
	int upper_bound;
	int value;
	int expected[5];
	int result;

	value = 1;
	upper_bound = 0;
	ft_insert_at(arr, &value, 0, sizeof(int), upper_bound);
	ft_memcpy(expected, (int []){1,0,0,0,0},sizeof(expected)); 
	result = array_eq(arr, expected, 5);
	FT_ASSERT(result, "SUCCES inserting at index 0 with upper bound equal 0"); 
	upper_bound++;

	value = 3;
	ft_insert_at(arr, &value, 0, sizeof(int), upper_bound);
	ft_memcpy(expected, (int []){3,1,0,0,0},sizeof(expected)); 
	result = array_eq(arr, expected, 5);
	FT_ASSERT(result, "SUCCES inserting at index 0 with upper bound equal 1"); 
	upper_bound++;

	value = -3;
	ft_insert_at(arr, &value, 2, sizeof(int), upper_bound);
	ft_memcpy(expected, (int []){3,1,-3,0,0},sizeof(expected)); 
	result = array_eq(arr, expected, 5);
	FT_ASSERT(result, "SUCCES inserting at index equal to upper bound 2"); 
	upper_bound++;

	value = 39;
	ft_insert_at(arr, &value, 2, sizeof(int), upper_bound);
	ft_memcpy(expected, (int []){3,1,39,-3,0},sizeof(expected)); 
	result = array_eq(arr, expected, 5);
	FT_ASSERT(result, "SUCCES inserting at index 2 with upper bound equal 3"); 
}
