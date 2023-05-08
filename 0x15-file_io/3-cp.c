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
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_count, write_count;
	char buffer[BUFFER_SIZE];
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]), exit(97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, permissions);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_count = write(fd_to, buffer, read_count);
		if (write_count != read_count)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (read_count == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98);

	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
