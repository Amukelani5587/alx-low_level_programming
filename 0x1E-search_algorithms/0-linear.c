#include "search_algos.h"
/**
 * linear_search - a function that searches for a value
 * in an array of integers using the Linear search algorithm
 * @array: array of integer
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: return the first index where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	uint i = 0;

	if (!array || size == 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
