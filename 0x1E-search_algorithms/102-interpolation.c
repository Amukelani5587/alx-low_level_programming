#include "search_algos.h"
/**
 * interpolation_search - a function that searches for a value
 * in a sorted array of integers using the interpolation search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: return the first index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	uint high = 0, low = 0, pos = 0;

	if (!array || size == 0)
		return (-1);
	high = size - 1;
	pos = low + (((double)(high - low) /
		      (array[high] - array[low])) * (value - array[low]));
	if (pos > size - 1)
		printf("Value checked array[%d] is out of range\n", pos);
	while (high >= low && array[high] >= value && array[low] <= value)
	{
		printf("Value checked array[%d] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (array[pos] > value)
			high = pos - 1;
		else
			low = pos + 1;
		pos = low + (((double)(high - low) /
			      (array[high] - array[low])) * (value - array[low]));
	}
	return (-1);
}
