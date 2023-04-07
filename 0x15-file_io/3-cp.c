#include "main.h"
#include <stdio.h>

/**
 * print_error - checks if files can be opened.
 * @msg: first argument.
 * @arg: second argument.
 * Return: no return.
 */
void print_error(const char *msg, const char *arg)
{
    dprintf(STDERR_FILENO, msg, arg);
    exit(EXIT_FAILURE);
}

/**
 * main - checks the code.
 * @argc: first argument, the number of arguments.
 * @argv: second argument, arguments vector.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        print_error("Usage: %s file_from file_to\n", argv[0]);
    }

    int fd_from = open(argv[1], O_RDONLY);
    if (fd_from < 0)
    {
        print_error("Error: Can't read from file %s\n", argv[1]);
    }

    int fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to < 0)
    {
        close(fd_from);
        print_error("Error: Can't write to %s\n", argv[2]);
    }

    char buf[1024];
    ssize_t nread, nwritten;
    while ((nread = read(fd_from, buf, sizeof(buf))) > 0)
    {
        nwritten = write(fd_to, buf, nread);
        if (nwritten < 0)
        {
            close(fd_from);
            close(fd_to);
            print_error("Error: Can't write to %s\n", argv[2]);
        }
    }

    if (nread < 0)
    {
        close(fd_from);
        close(fd_to);
        print_error("Error: Can't read from file %s\n", argv[1]);
    }

    if (close(fd_from) < 0)
    {
        print_error("Error: Can't close fd %d\n", fd_from);
    }

    if (close(fd_to) < 0)
    {
        print_error("Error: Can't close fd %d\n", fd_to);
    }

    return EXIT_SUCCESS;
}
