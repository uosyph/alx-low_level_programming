#include "main.h"

/**
 * _stoi - converts chars to ints.
 * @char_to_convert: a char to convert.
 * Return: the converted int.
 */
unsigned int _stoi(char char_to_convert)
{
    return ((unsigned int)char_to_convert - '0');
}

/**
 * _strlen - calculates the length of the string.
 * @string: the string.
 * Return: the length of a string.
 */
unsigned int _strlen(const char *string)
{
    unsigned int i;

    for (i = 0; string[i]; i++)
        ;

    return (i);
}

/**
 * binary_to_uint - converts a string from binary to a decimal number.
 * @binary_string: a string to convert.
 * Return: the unsigned decimal number.
 */
unsigned int binary_to_uint(const char *binary_string)
{
    int i;
    unsigned int decimal, tmp, expo;

    if (!binary_string)
        return (0);

    decimal = tmp = 0;
    expo = 1;

    for (i = _strlen(binary_string) - 1; binary_string[i]; i--, expo *= 2)
    {
        if (binary_string[i] != '0' && binary_string[i] != '1')
            return (0);
        tmp = _stoi(binary_string[i]);
        decimal += tmp * expo;
    }

    return (decimal);
}
