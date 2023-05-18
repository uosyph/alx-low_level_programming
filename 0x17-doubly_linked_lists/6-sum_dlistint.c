#include "lists.h"

/**
 * sum_dlistint - Sums the elements in a linked list.
 * @head: Head of the linked list.
 * Return: The sum.
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *present;
	dlistint_t *next;
	int sum = 0;

	present = head;

	while (present != NULL)
	{
		next = present->next;
		sum += present->n;
		present = next;
	}
	return (sum);
}
