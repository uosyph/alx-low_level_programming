#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters.
 * @filename: first argument, filename.
 * @letters: second argument, numbers of letters printed.
 * Return: numbers of printed letters. if failed 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
    {
        return 0;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return 0;
    }

    char *buffer = (char *)malloc((letters + 1) * sizeof(char));
    if (buffer == NULL)
    {
        fclose(file);
        return 0;
    }

    size_t read_count = fread(buffer, sizeof(char), letters, file);
    if (read_count != letters)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    buffer[read_count] = '\0';
    ssize_t write_count = write(STDOUT_FILENO, buffer, read_count);
    if (write_count != (ssize_t)read_count)
    {
        free(buffer);
        fclose(file);
        return 0;
    }

    free(buffer);
    fclose(file);
    return write_count;
}
