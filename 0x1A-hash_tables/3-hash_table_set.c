#include "hash_tables.h"

/**
 * hash_table_set - adds or updates an element in a hash table.
 * @ht: a pointer to the hash table.
 * @key: a key to add.
 * @value: the value associated with key.
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_t;
	char *copy_value;
	unsigned long int index, counter;

	if (ht == NULL || key == NULL || value == NULL || *key == "\0")
	{
		return (0);
	}

	copy_value = strdup(value);
	if (copy_value == NULL)
	{
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);
	for (counter = index; ht->array[counter]; counter++)
	{
		if (strcmp(ht->array[counter]->key, key) == 0)
		{
			free(ht->array[counter]->value);
			ht->array[counter]->value = copy_value;
			return (1);
		}
	}

	new_t = malloc(sizeof(hash_node_t));
	if (new_t == NULL)
	{
		free(copy_value);
		return (0);
	}

	new_t->key = strdup(key);
	if (new_t->key == NULL)
	{
		free(new_t);
		return (0);
	}

	new_t->value = copy_value;
	new_t->next = ht->array[index];
	ht->array[index] = new_t;

	return (1);
}
