#include "lists.h"
#include <string.h>

/**
 * add_dnodeint - Inserts a node to a linked list head.
 * @head: The linked list head.
 * @n: Integer with value.
 * Return: Pointer to new the node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{

	dlistint_t *new_node = NULL;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(new_node));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (new_node);
}
