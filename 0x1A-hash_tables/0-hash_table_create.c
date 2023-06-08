#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: the size of the array.
 * Return: a pointer to the new hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int counter;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		return (NULL);
	}
	for (counter = 0; counter < size; counter++)
	{
		ht->array[counter] = NULL;
	}

	return (ht);
}
