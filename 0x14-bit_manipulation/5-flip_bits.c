#include "main.h"

/**
 * flip_bits - returns the number of bits you
 * need to flip to get from one number to another.
 * @n: first number.
 * @m: second number.
 * Return: number of bits needed to filp from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor_result = n ^ m;
    unsigned int count = 0;

    while (xor_result != 0)
    {
        count += xor_result & 1;
        xor_result >>= 1;
    }

    return count;
}

int main()
{
    unsigned long int n = 0b10101010;
    unsigned long int m = 0b11001100;
    unsigned int result = flip_bits(n, m);

    printf("The number of bits needed to flip from %lu to %lu is %u\n", n, m, result);

    return 0;
}
