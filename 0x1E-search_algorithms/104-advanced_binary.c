#include "search_algos.h"

/**
 * advanced_binary_recursive - Uses recursive search to find the given value
 * @array: Pointer to the first element of the sub array to search in
 * @left: Starting index of the sub array to search
 * @right: Ending index of the sub array to search
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t index;

	if (right < left)
		return (-1);

	printf("Searching in array: ");

	for (index = left; index < right; index++)
		printf("%d, ", array[index]);

	printf("%d\n", array[index]);

	index = left + (right - left) / 2;
	if (array[index] == value && (index == left || array[index - 1] != value))
		return (index);
	if (array[index] >= value)
		return (advanced_binary_recursive(array, left, index, value));

	return (advanced_binary_recursive(array, index + 1, right, value));
}

/**
 * advanced_binary - Uses advanced binary search to find the given value
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
