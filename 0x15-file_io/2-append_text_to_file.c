#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: first argument, the filename.
 * @text_content: second argument, the added content.
 * Return: 1 if the file exists, -1 if file does not exist or failed.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    if (filename == NULL)
    {
        return -1;
    }
    if (text_content == NULL)
    {
        return 1;
    }

    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        return -1;
    }

    int len = strlen(text_content);
    int bytes_written = fwrite(text_content, sizeof(char), len, fp);
    fclose(fp);

    if (bytes_written != len)
    {
        return -1;
    }

    return 1;
}
