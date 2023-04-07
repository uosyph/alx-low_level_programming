#include "main.h"

/**
 * get_endianness - check the endianness.
 * Return: if big endian 0, if little endian 1.
 */
int get_endianness(void)
{
	char *j;
	unsigned int i = 1;

	j = (char *)&i;

	return ((int)*j);
}
