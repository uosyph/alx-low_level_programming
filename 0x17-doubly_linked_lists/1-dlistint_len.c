#include "lists.h"
#include <stdio.h>

/**
 * dlistint_len - Finds the number of nodes in a doubly linked list.
 * @h: The linked list.
 * Return: Number of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t near_nodes = 0;
	const dlistint_t *present = h;

	while (present != NULL)
	{
		present = present->next;
		near_nodes++;
	}

	return (near_nodes);
}
