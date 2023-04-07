#include "main.h"

/**
 * get_bit - returns the value of a bit at
 * a given index.
 * @n: unsigned long int input.
 * @index: index of the bit.
 * Return: integer value of 0 or 1.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
    {
        return -1;
    }

    return (n >> index) & 1;
}

int main()
{
    unsigned long int n = 0b10101010;
    unsigned int index = 3;
    int bit_value = get_bit(n, index);

    if (bit_value == -1)
    {
        printf("Error: index out of range\n");
    }
    else
    {
        printf("The bit value at index %u is %d\n", index, bit_value);
    }

    return 0;
}
