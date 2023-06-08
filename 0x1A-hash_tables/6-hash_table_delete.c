#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: a pointer to the hash table.
 * Return: void.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int counter;

	for (counter = 0; counter < ht->size; counter++)
	{
		if (ht->array[counter] != NULL)
		{
			node = ht->array[counter];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}

	free(head->array);
	free(head);
}
