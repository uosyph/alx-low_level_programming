#include "lists.h"

/**
 * free_dlistint - Frees a listint_t type list.
 * @head: Head of the linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *present;
	dlistint_t *next;

	present = head;

	while (present != NULL)
	{
		next = present->next;
		free(present);
		present = next;
	}
}
