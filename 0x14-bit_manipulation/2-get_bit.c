#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: a given number.
 * @index: an index binary number.
 * Return: binary (1 or 0), -1 on failure.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    int bit;
    unsigned int max_bits;

    /* check if index is within range */
    max_bits = (sizeof(unsigned long int) * 8);
    if (index > max_bits)
        return (-1);

    /* shift the number to index to find bit */
    bit = ((n >> index) & 1);

    return (bit);
}
