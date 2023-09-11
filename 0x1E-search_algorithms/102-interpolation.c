#include "search_algos.h"

/**
 * interpolation_search - Uses interpolation search to find the given value
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	low = 0;
	high = size - 1;

	if (array == NULL)
		return (-1);

	while (array[high] != array[low])
	{
		pos = low + (((double)(high - low) /
					  (array[high] - array[low])) *
					 (value - array[low]));

		if (pos > size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		else
		{
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		}

		if (array[pos] < value)
			low = pos + 1;
		else if (array[pos] > value)
			high = pos - 1;
		else
			return (pos);
	}

	if (array[low] == value)
		return (low);

	return (-1);
}
