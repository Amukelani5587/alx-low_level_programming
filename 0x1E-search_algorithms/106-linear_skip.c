#include "search_algos.h"
#include <math.h>
/**
 * linear_skip - a function that searches for a value
 * in a sorted array of integers
 * @list: a pointer to the head of the list to search in
 * @value: the value to search for
 * Return: return the first index where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp, *curr;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->n < value && temp->next)
	{
		curr = temp;
		if (temp->express)
			temp = temp->express;
		else
		{
			while (temp->next)
				temp = temp->next;
		}
		if (temp->next)
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
