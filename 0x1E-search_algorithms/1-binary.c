#include "search_algos.h"

/**
 * print_search_array - Prints the array that's being searched
 * @array: Pointer to the array being searched
 * @start: Index to start printing at
 * @end: Index to finish printing at
 **/
void print_search_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");

	i = start;
	while (i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * binary_search - Uses a binary search to find the given value in an array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int binary_search(int *array, size_t size, int value)
{
	int left, right, compare;

	left = compare = 0;
	right = size - 1;

	while (left <= right)
	{
		print_search_array(array, left, right);

		compare = (left + right) / 2;
		if (array[compare] == value)
			return (compare);
		else if (array[compare] > value)
			right = compare;
		else if (array[compare] < value)
			left = compare + 1;
	}
	return (-1);
}
