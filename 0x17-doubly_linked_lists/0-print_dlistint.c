#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints the elements of a doubly linked list.
 * @h: The linked list.
 * Return: Number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t near_nodes = 0;
	const dlistint_t *present = h;

	while (present != NULL)
	{
		printf("%i\n", present->n);
		present = present->next;
		near_nodes++;
	}

	return (near_nodes);
}
