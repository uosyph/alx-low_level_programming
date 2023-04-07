#include "main.h"
#include <stdio.h>

/**
 * main - copies the content of a file to another file.
 * @argc: number of parameters that go into main.
 * @argv: pointer of array of pointers containing strings entering main.
 * Return: always 0.
 */
int main(int argc, char **argv)
{
    int filefrom, fileto, copyfrom, copyto, closefrom, closeto;
    char buffer[1024];

    if (argc != 3)
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

    filefrom = open(argv[1], O_RDONLY);

    if (filefrom == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    
    fileto = open(argv[2], O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0664);
    
    if (fileto == -1)
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
    
    while ((copyfrom = read(filefrom, buffer, 1024)) > 0)
    {
        copyto = write(fileto, buffer, copyfrom);
        if (copyfrom != copyto)
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
    }
    
    if (copyfrom == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    
    closefrom = close(filefrom);
    
    if (closefrom == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filefrom), exit(100);
    
    closeto = close(fileto);
    
    if (closeto == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileto), exit(100);
    
    return (0);
}
