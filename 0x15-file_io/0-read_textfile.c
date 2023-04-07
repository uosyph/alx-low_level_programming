#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters.
 * @filename: first argument, the name of the file.
 * @letters: second argument, numbers of letters printed.
 * Return: numbers of printed letters. if failed 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file;
    ssize_t readfile, writefile;
    char *mbuffer;

    if (!filename)
        return (0);

    file = open(filename, O_RDONLY);

    if (file == -1)
        return (0);

    mbuffer = malloc(sizeof(char) * (letters));
    if (!mbuffer)
        return (0);

    readfile = read(file, mbuffer, letters);
    writefile = write(STDOUT_FILENO, mbuffer, readfile);

    close(file);
    free(mbuffer);
    
    return (writefile);
}
