#include "main.h"

/**
 * get_endianness - check the endianness.
 * Return: if big endian 0, if little endian 1.
 */
int get_endianness(void)
{
	unsigned int i;
	char *j;

	i = 1;
	j = (char *)&i;

	return ((int)*j);
}
