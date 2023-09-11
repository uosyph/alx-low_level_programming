#include "search_algos.h"

/**
 * _binary_search - Uses binary search to find the given value in an array
 * @array: Pointer to the first element of the array to search in
 * @left: Starting index of the sub array to search
 * @right: Ending index of the sub array to search
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t index;

	if (array == NULL)
		return (-1);

	while (right >= left)
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

/**
 * exponential_search - Uses exponential search to find the given value
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int exponential_search(int *array, size_t size, int value)
{
	size_t index = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (index = 1; index < size && array[index] <= value; index = index * 2)
			printf("Value checked array[%ld] = [%d]\n", index, array[index]);
	}

	right = index < size ? index : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", index / 2, right);

	return (_binary_search(array, index / 2, right, value));
}
