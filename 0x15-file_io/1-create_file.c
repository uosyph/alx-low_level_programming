#include "main.h"

/**
 * create_file - creates a file.
 * @filename: first argument, filename.
 * @text_content: second argument, the content written to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    if (filename == NULL)
    {
        return -1;
    }

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        return -1;
    }

    if (text_content != NULL)
    {
        ssize_t write_count = write(fd, text_content, strlen(text_content));
        if (write_count == -1)
        {
            close(fd);
            return -1;
        }
    }

    close(fd);

    return 1;
}
