#include "search_algos.h"
/**
 * exponential_search - a function that searches for a value
 * in a sorted array of integers using the exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: return the first index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	uint i = 0, high = 0, low = 0, mid = 0;
	uint pow = 1;

	if (!array || size == 0)
		return (-1);
	while (pow < size && array[pow] < value)
	{
		printf("Value checked array[%d] = [%d]\n", pow, array[pow]);
		pow *= 2;
	}
	low = pow / 2;
	if (pow >= size)
		high = size - 1;
	else
		high = pow;
	printf("Value found between indexes [%d] and [%d]\n", low, high);
	while (high >= low)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			if (i != low)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
		mid = (high + low) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}
