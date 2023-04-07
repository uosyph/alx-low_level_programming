#include "main.h"

/**
 * create_file - creates a file.
 * @filename: first argument, the name of the file.
 * @text_content: second argument, the content written to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int filedata, content, length = 0;

    if (filename == 0)
        return (-1);

    filedata = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

    if (filedata == -1)
        return (-1);

    if (text_content)
    {
        while (text_content[length])
            length++;
        content = write(filedata, text_content, length);

        if (content == -1)
            return (-1);
    }

    close(filedata);

    return (1);
}
