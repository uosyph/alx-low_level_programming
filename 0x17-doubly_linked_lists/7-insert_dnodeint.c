#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts node at a specific index.
 * @h: Head of linked list.
 * @idx: Index of the new node.
 * @n: Integer with new node value.
 * Return: The new inserted node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *tmp;
	unsigned int compare = 0;

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;

	tmp = *h;
	while (tmp != NULL)
	{
		if ((compare + 1) == idx)
		{
			new_node->next = tmp->next;
			tmp->next = new_node;
			new_node->prev = tmp;
			return (new_node);
		}
		compare++;
		tmp = tmp->next;
	}

	if ((compare + 1) == idx)
	{
		return (add_dnodeint_end(h, n));
	}

	free(new_node);

	return (NULL);
}
