#include "main.h"

/**
 * print_binary - prints the binary representation
 * of a number.
 * @i: unsigned long int.
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
    int i;
    unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

    while (mask > 0)
    {
        putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }
}

int main()
{
    unsigned long int n = 123456789;

    printf("Binary representation of %lu is: ", n);
    print_binary(n);
    printf("\n");

    return 0;
}
