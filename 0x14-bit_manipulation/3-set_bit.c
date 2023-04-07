#include "main.h"

/**
 * set_bit - sets the value of a bit to 1
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 * Return: if worked 1, if didn't -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
    {
        return -1;
    }
    *n |= (1ul << index);

    return 1;
}

int main()
{
    unsigned long int n = 0b10101010;
    unsigned int index = 2;
    int result = set_bit(&n, index);

    if (result == -1)
    {
        printf("Error: index out of range\n");
    }
    else
    {
        printf("The new value of n is %lu\n", n);
    }

    return 0;
}
