#include "search_algos.h"

/**
 * low - Finds the lower number between two number
 * @step: First number
 * @size: Second number
 * Return: Lower value number
 **/
size_t low(size_t step, size_t size)
{
	if (step < size)
		return (step);
	return (size);
}

/**
 * jump_search - Uses a jump search to find the given value in an array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index that the value is found, -1 if value not found
 **/
int jump_search(int *array, size_t size, int value)
{
	size_t step, previous_step;

	previous_step = 0;
	step = 0;

	if (array == NULL)
		return (-1);

	while (array[low(step, size - 1)] < value && step < size)
	{
		printf("Value checked array[%lu] = [%d]\n",
			   low(step, size - 1),
			   array[low(step, size - 1)]);
		previous_step = step;
		step += sqrt(size);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   previous_step,
		   step);

	while (array[previous_step] <= (int)step && previous_step < size)
	{
		printf("Value checked array[%lu] = [%d]\n",
			   previous_step,
			   array[previous_step]);

		if (array[previous_step] == value)
			return (previous_step);
		if (previous_step == low(step, size))
			return (-1);

		previous_step++;
	}

	return (-1);
}
