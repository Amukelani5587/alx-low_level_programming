#include "search_algos.h"
/**
 * printer - Prints an array
 * @array: Target array
 * @low: Left index of @array
 * @high: Right index of @array
 */
void printer(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i == high)
			printf("\n");
		else
			printf(", ");
	}
}

/**
 * binary_search - a function that searches for a value
 * in a sorted array of integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: return the first index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t high = 0, low = 0, mid = 0;

	if (!array || size == 0)
		return (-1);
	high = size - 1;
	while (high >= low)
	{
		printer(array, low, high);
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
