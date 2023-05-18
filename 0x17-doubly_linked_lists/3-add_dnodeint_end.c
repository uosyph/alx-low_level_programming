#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * add_dnodeint_end - Adds a node at the end of a linked list.
 * @head: The character to print.
 * @n: String for the new node.
 * Return: The new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *present;
	dlistint_t *new_node;

	present = *head;
	while (present && present->next != NULL)
	{
		present = present->next;
	}

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = present;

	if (present)
	{
		present->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	return (new_node);
}
