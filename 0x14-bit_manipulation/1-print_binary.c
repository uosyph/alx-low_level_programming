#include "main.h"

/**
 * print_binary - converts an unsigned integer to binary.
 * @n: the unsigned integer.
 * Return: the converted binary.
 */
void print_binary(unsigned long int n)
{
    unsigned long int n_copy = n, mask = 1;
    int length = 0;

    while (n_copy > 0)
    {
        length++;
        n_copy >>= 1;
    }
    length -= 1;

    /* create mask based on length of num */
    if (length > 0)
        mask = mask << length;

    /* match each rightmost bit to see if 1 or 0 */
    while (mask > 0)
    {
        if (n & mask)
            _putchar('1');
        else
            _putchar('0');

        mask >>= 1;
    }
}
