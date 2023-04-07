#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: first argument, the name of the file.
 * @text_content: second argument, the added content.
 * Return: 1 if the file exists, -1 if failed or file doesn't exist.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int filedata, writefile, length = 0;

    if (filename == 0)
        return (-1);

     filedata = open(filename, O_WRONLY | O_APPEND);

    if (filedata == -1)
        return (-1);

    if (text_content)
    {
        while (text_content[length])
            length++;
        writefile = write(filedata, text_content, length);
        if (writefile == -1)
            return (-1);
    }

    close(filedata);

    return (1);
}
