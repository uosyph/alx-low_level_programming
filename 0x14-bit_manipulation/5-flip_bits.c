#include "main.h"

/**
 * flip_bits - gets the number of bits you would
 * need to flip to get from one number to another.
 * @n: the first number.
 * @m: the second number.
 * Return: the number of bits needed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor = n ^ m;
    unsigned int bits = 0;

    while (xor != 0)
    {
        bits += xor & 1;
        xor >>= 1;
    }

    return bits;
}
