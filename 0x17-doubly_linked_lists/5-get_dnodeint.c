#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node of a listint_t linked list.
 * @head: Head of the linked list
 * @index: Node index to return.
 * Return: The node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *present;

	if (head == NULL)
	{
		return (0);
	}

	present = head;

	while (index != 0)
	{
		present = present->next;
		index--;
		if (present == NULL)
		{
			return (0);
		}
	}

	return (present);
}
