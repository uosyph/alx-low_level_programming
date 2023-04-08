#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: a given number.
 * @index: an index binary number.
 * Return: 1 on success, -1 on failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int max_bits;
    unsigned long int mask = 1;

    /* check if index is within range */
    max_bits = (sizeof(unsigned long int) * 8);
    if (index > max_bits)
        return (-1);

    /* create a mask with 0 at index to work with the it */
    mask = ~(mask << index);
    *n = (*n & mask);

    return (1);
}
