#include "search_algos.h"
#include <math.h>
/**
 * jump_list - a function that searches for a value
 * in a sorted array of integers using the Jump search algorithm
 * @list: a pointer to the head of the list to search in
 * @size: is the number of elements in array
 * @value: the value to search for
 * Return: return the first index where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	int block = 0;
	listint_t *temp, *curr;

	if (!list || size == 0)
		return (NULL);
	temp = list;
	block = sqrt(size);
	while (temp->n < value && temp->next)
	{
		curr = temp;
		while (temp->next && block > 0)
		{
			temp = temp->next;
			block--;
		}
		block = sqrt(size);
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", curr->index,
	       temp->index);
	while (curr->index <= temp->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		if (!curr->next)
			break;
		curr = curr->next;
	}
	return (NULL);
}
