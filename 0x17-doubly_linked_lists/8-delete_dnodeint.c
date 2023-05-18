#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at specific index.
 * @head: Head of linked list.
 * @index: Index of node to delete.
 * Return: 1 if success, -1 if failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *delete;
	dlistint_t *tmp;
	unsigned int compare = 0;

	if (head == NULL)
	{
		return (-1);
	}

	tmp = *head;
	while (tmp != NULL)
	{
		if (index == 0)
		{
			delete = tmp;
			*head = tmp->next;
			if (tmp->next)
				tmp->next->prev = NULL;
			free(delete);
			return (1);
		}
		else if ((compare + 1) == index)
		{
			delete = tmp->next;
			tmp->next = (tmp->next)->next;
			tmp->prev = (tmp->next)->prev;
			free(delete);
			return (1);
		}

		compare++;
		tmp = tmp->next;
	}

	return (-1);
}
