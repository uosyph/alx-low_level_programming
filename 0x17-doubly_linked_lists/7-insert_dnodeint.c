#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts node at a specific index.
 * @h: Head of linked list.
 * @idx: Index of the new node.
 * @n: New node value.
 * Return: The inserted node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *present;
	dlistint_t *new;

	if (h == NULL)
	{
		return (0);
	}

	present = *h;

	while (idx != 0)
	{
		present = present->next;
		idx--;
		if (present == NULL)
			return (NULL);
	}

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = n;
	new->next = present;
	new->prev = present->prev;

	if (present->prev != NULL)
	{
		present->prev->next = new;
	}

	return (present);
}
