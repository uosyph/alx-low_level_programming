#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 * Return: if success 1, if not -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
    {
        return -1;
    }
    *n &= ~(1ul << index);

    return 1;
}

int main()
{
    unsigned long int n = 0b10101010;
    unsigned int index = 2;
    int result = clear_bit(&n, index);

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
