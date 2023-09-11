#include "search_algos.h"

/**
 * binary_search - Uses binary search to find the given value in an array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int binary_search(int *array, size_t size, int value)
{
	size_t index, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");

		for (index = left; index < right; index++)
			printf("%d, ", array[index]);

		printf("%d\n", array[index]);

		index = left + (right - left) / 2;
		if (array[index] == value)
			return (index);
		if (array[index] > value)
			right = index - 1;
		else
			left = index + 1;
	}

	return (-1);
}
