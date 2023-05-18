#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes node at specific index.
 * @head: Head of linked list.
 * @index: Index of node to delete.
 * Return: 1 if success, -1 if failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *present;

	if (head == NULL)
	{
		return (-1);
	}

	present = *head;

	if (present == NULL)
	{
		return (-1);
	}

	while (index != 0)
	{
		present = present->next;
		index--;
		if (present == NULL)
		{
			return (-1);
		}
	}

	if (present->prev != NULL)
	{
		present->prev->next = present->next;
	}
	else
	{
		*head = present->next;
		if (present->next != NULL)
		{
			present->next->prev = NULL;
		}
		free(present);
	}

	return (1);
}
