#include "main.h"
#define BUFFER_SIZE 1024

/**
*main: copy text from one file to another
*@argc: no. of  arguments
*@argv: arguments
*Return: 0 or error
*
*
*
*
*
*
*/
int main(int argc, char **argv)
{
    int fd_from, fd_to, read_count, write_count;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return (97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        print_error("Error: Can't read from file", argv[1], fd_from, -1);
        return (98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        print_error("Error: Can't write to", argv[2], fd_from, fd_to);
        return (99);
    }

    do {
        read_count = read(fd_from, buffer, BUFFER_SIZE);
        if (read_count == -1)
        {
            print_error("Error: Can't read from file", argv[1], fd_from, fd_to);
            return (98);
        }

        write_count = write(fd_to, buffer, read_count);
        if (write_count == -1)
        {
            print_error("Error: Can't write to", argv[2], fd_from, fd_to);
            return (99);
        }
    } while (read_count > 0);

    if (close(fd_from) == -1)
    {
        print_error("Error: Can't close fd", argv[1], fd_from, fd_to);
        return (100);
    }

    if (close(fd_to) == -1)
    {
        print_error("Error: Can't close fd", argv[2], fd_from, fd_to);
        return (100);
    }

    return (0);
}

/**
 * print_error - Prints an error message to the standard error output.
 * @message: The message to print.
 * @filename: The name of the file.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void print_error(char *message, char *filename, int fd_from, int fd_to)
{
    dprintf(STDERR_FILENO, "%s %s", message, filename);
    if (fd_from != -1)
        close(fd_from);
    if (fd_to != -1)
        close(fd_to);
    dprintf(STDERR_FILENO, "\n");
}
