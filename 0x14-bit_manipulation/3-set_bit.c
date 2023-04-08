#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: a given number.
 * @index: an index binary number.
 * Return: 1 on success, -1 on failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    unsigned int max_bits;
    unsigned long int mask = 1;

    /* check if index is within range */
    max_bits = (sizeof(unsigned long int) * 8);
    if (index > max_bits)
        return (-1);

    /* create a mask with 1 at index to work with the it */
    mask <<= index;
    *n = (*n | mask);

    return (1);
}
